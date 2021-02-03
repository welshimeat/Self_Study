#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1000000;
int N, M, a, b, s, e, map[1001][1001], visited[1001];
queue<pair<int, int>> q;
vector<int> v[1001];
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> e >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs();

	return 0;
}

void bfs() {
	int node, dist;
	bool found = false;
	q.push({ s, 0 });
	visited[s] = -1;
	while (!q.empty()) {
		node = q.front().first;
		dist = q.front().second;
		q.pop();
		if (node == e) {
			found = true;
			break;
		}
		for (int i = 0; i < v[node].size(); i++) {
			if (!visited[v[node][i]] || visited[v[node][i]] > dist + 1) {
				visited[v[node][i]] = dist + 1;
				q.push({ v[node][i], dist + 1 });
			}
		}
	}
	if (found) cout << dist;
	else cout << -1;
}