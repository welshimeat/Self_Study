#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

queue<tuple<int, int, char>> q;
int N, direction_x[4] = { 1, -1, 0, 0 }, direction_y[4] = { 0, 0, 1, -1 }, normal = 0, blind = 0;
char map[100][100], visited[100][100];
void normal_bfs(int x, int y);
void blind_bfs(int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				normal_bfs(i, j);
				normal++;
			}
		}
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				blind_bfs(i, j);
				blind++;
			}
		}
	}
	cout << normal << ' ' << blind << '\n';

	return 0;
}

void normal_bfs(int x, int y) {
	char color;

	q.push({ x, y, map[x][y] });
	visited[x][y] = 1;
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		color = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && !visited[new_x][new_y] && map[new_x][new_y] == color) {
				q.push({ new_x, new_y, color });
				visited[new_x][new_y] = 1;
			}
		}
	}
}

void blind_bfs(int x, int y) {
	char color;

	q.push({ x, y, map[x][y] });
	visited[x][y] = 1;
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		color = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && !visited[new_x][new_y]) {
				if (color != 'B' && map[new_x][new_y] != 'B') {
					q.push({ new_x, new_y, color });
					visited[new_x][new_y] = 1;
				}
				else if(map[new_x][new_y] == color){
					q.push({ new_x, new_y, color });
					visited[new_x][new_y] = 1;
				}
			}
		}
	}
}