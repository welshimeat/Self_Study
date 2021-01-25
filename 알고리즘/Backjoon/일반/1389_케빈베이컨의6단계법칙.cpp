#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int bfs(int);
int N, M, rel[101][101], A, B;
int visited[101], dist[101];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int person = 0, min = 999999, total;

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> A >> B;
		rel[A][B] = 1;
		rel[B][A] = 1;
	}
	for (int i = N; i >= 1; i--) {
		total = bfs(i);
		if (total <= min) {
			min = total;
			person = i;
		}
		memset(visited, 0, sizeof(visited));
		memset(dist, 0, sizeof(dist));
	}
	cout << person;

	return 0;
}

int bfs(int dep) {
	int total = 0;

	visited[dep] = 1;
	q.push(dep);
	while (!q.empty()) {
		int des = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (visited[i] != 1 && rel[des][i] == 1) {
				dist[i] = dist[des] + 1;
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		total += dist[i];
	}
	return total;
}