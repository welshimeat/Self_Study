#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int N, M, visited[1001][1001][2];
char map[1001][1001];
int direction_x[4] = { 1, -1, 0, 0 }, direction_y[4] = { 0, 0, 1, -1 };
queue<tuple<int, int, int, bool>> q;
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	return 0;
}

void bfs() {
	q.push({ 1, 1, 1, false });
	visited[1][1][false] = 1;
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int dist = get<2>(q.front());
		bool used = get<3>(q.front());
		q.pop();
		if (x == N && y == M) {
			cout << dist << '\n';
			return;
		}
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 1 && new_x <= N && new_y >= 1 && new_y <= M) {
				if (map[new_x][new_y] == '0' && (!visited[new_x][new_y][used] || visited[new_x][new_y][used] > dist + 1)) {
					q.push({ new_x, new_y, dist + 1, used });
					visited[new_x][new_y][used] = dist + 1;
				}
				else if (used == false && map[new_x][new_y] == '1' && (!visited[new_x][new_y][!used] || visited[new_x][new_y][!used] > dist + 1)) {
					q.push({ new_x, new_y, dist + 1, !used });
					visited[new_x][new_y][!used] = dist + 1;
				}
			}
		}
	}
	cout << -1 << '\n';	
}