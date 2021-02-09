#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, visited[20001];
vector<int> v[20001];
queue<pair<int, int>> q;
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int A, B;

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	bfs();

	return 0;
}

void bfs() {
	int max = 0;
	vector<int> answer;

	q.push({ 1, 0 });
	visited[1] = -1;
	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (dist == max) {
			answer.push_back(node);
		}
		else {
			max = dist;
			answer.clear();
			answer.push_back(node);
		}
		for (int i = 0; i < v[node].size(); i++) {
			if (!visited[v[node][i]]) {
				visited[v[node][i]] = 1;
				q.push({ v[node][i], dist + 1 });
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << *min_element(answer.begin(), answer.end()) << ' ' << max << ' ' << answer.size();
}