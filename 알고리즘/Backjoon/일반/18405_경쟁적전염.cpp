#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
queue<tuple<int, int, int>> q;
void bfs();
int N, K, map[201][201], visited[201][201] = { 0 }, S, X, Y,
direction_x[4] = { 0, 0, 1, -1 }, direction_y[4] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				q.push({ map[i][j], i, j });
				visited[i][j] = 1;
			}
		}
	}
	cin >> S >> X >> Y;

	bfs();
	cout << map[X][Y] << '\n';

	return 0;
}

void bfs() {
	for (int i = 0; i < S; i++) {
		if (map[X][Y] != 0) {
			break;
		}
		while (!q.empty()) {
			auto value = q.front();
			pq.push(value);
			q.pop();
		}
		while (!pq.empty()) {
			auto value = pq.top();
			pq.pop();
			int x = get<1>(value);
			int y = get<2>(value);
			for (int j = 0; j < 4; j++) {
				int new_x = x + direction_x[j];
				int new_y = y + direction_y[j];
				if (new_x > 0 && new_x <= N && new_y > 0 && new_y <= N && map[new_x][new_y] == 0) {
					map[new_x][new_y] = map[x][y];
					q.push({ map[new_x][new_y], new_x, new_y });
					visited[new_x][new_y] = 1;
				}
			}
		}
	}
}