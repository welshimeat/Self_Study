#include <iostream>
#include <queue>
using namespace std;

int R, C, direction_x[4] = { 1, -1, 0, 0 }, direction_y[4] = { 0, 0, 1, -1 },
	sheep = 0, wolf = 0;
char map[250][250], visited[250][250];
queue<pair<int, int>> q;
void bfs(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') visited[i][j] = 1;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	cout << sheep << ' ' << wolf << '\n';

	return 0;
}

void bfs(int x, int y) {
	int o = 0, v = 0;

	q.push({ x, y });
	visited[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (map[x][y] == 'o') o++;
		else if (map[x][y] == 'v') v++;
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 0 && new_x < R && new_y >= 0 && new_y < C && !visited[new_x][new_y]) {
				q.push({ new_x, new_y });
				visited[new_x][new_y] = 1;
			}
		}
	}
	if (o > v) {
		sheep += o;
	}
	else {
		wolf += v;
	}

}