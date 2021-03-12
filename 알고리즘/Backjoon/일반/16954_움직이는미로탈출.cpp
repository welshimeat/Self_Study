#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char map[8][8][8];
bool visited[8][8];
queue<tuple<int, int, int>> q;
int direction_x[9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 },
direction_y[9] = { 1, 0 ,-1, 1, 0, -1, 1, 0, -1 };

bool bfs();
void moveBlock(int index);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> map[0][i][j];
		}
	}
	for (int i = 1; i < 8; i++) {
		moveBlock(i);
	}

	if (bfs()) cout << 1;
	else cout << 0;

	return 0;
}

bool bfs() {
	q.push({ 7, 0, 0 });
	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int second = get<2>(q.front());
		q.pop();
		if (x == 0 && y == 7) return true;
		if (map[second][x][y] == '#') continue;
		for (int i = 0; i < 9; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (second < 7) {
				if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && map[second][new_x][new_y] == '.') {
					q.push({ new_x, new_y, second + 1 });
				}
			}
			else {
				if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8 && map[second][new_x][new_y] == '.' && !visited[new_x][new_y]) {
					visited[new_x][new_y] = 1;
					q.push({ new_x, new_y, second });
				}
			}
			
		}
	}
	return false;
}

void moveBlock(int index) {
	for (int i = 6; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			map[index][i + 1][j] = map[index-1][i][j];
		}
	}
	for (int j = 0; j < 8; j++) {
		map[index][0][j] = '.';
	}
}