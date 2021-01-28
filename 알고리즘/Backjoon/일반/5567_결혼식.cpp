#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int n, m, a, b, visited[501];
unordered_set<int> s[501];
queue<int> q;
void bfs(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		s[a].insert(b);
		s[b].insert(a);
	}

	bfs(1);
	
	return 0;
}

void bfs(int index) {
	int cnt = 0, limit, num = 0;

	q.push(index);
	visited[index] = 1;
	limit = s[index].size() + 1;
	while (!q.empty()){
		index = q.front();
		q.pop();
		for (auto iter = s[index].begin(); iter != s[index].end(); iter++) {
			if (visited[*iter] == 0) {
				visited[*iter] = 1;
				q.push(*iter);
				num++;
			}
		}
		if (++cnt == limit) break;
	}

	cout << num << '\n';
}