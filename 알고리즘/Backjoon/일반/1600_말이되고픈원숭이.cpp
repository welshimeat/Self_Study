#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

queue<tuple<int, int, int ,int>> q;
int K, W, H, map[200][200], visited[200][200][31],
direction_x[4] = { 1, -1, 0, 0 }, direction_y[4] = { 0, 0, 1, -1 },
horse_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }, horse_y[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
void bfs(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
		}
	}

	bfs(0, 0);

	return 0;
}

void bfs(int x, int y) {
	bool found = false;
	int k, cnt;

	q.push({ x, y, K, 0 });
	visited[x][y][K] = 1;
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		k = get<2>(q.front());
		cnt = get<3>(q.front());
		if (x == H - 1 && y == W - 1) {
			found = true;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 0 && new_x < H && new_y >= 0 && new_y < W && !visited[new_x][new_y][k] && map[new_x][new_y] != 1) {
				q.push({ new_x, new_y, k, cnt + 1 });
				visited[new_x][new_y][k] = 1;
			}
		}
		if (k >= 1) {
			for (int i = 0; i < 8; i++) {
				int new_x = x + horse_x[i];
				int new_y = y + horse_y[i];
				if (new_x >= 0 && new_x < H && new_y >= 0 && new_y < W && !visited[new_x][new_y][k-1] && map[new_x][new_y] != 1) {
					q.push({ new_x, new_y, k - 1, cnt + 1 });
					visited[new_x][new_y][k-1] = 1;
				}
			}
		}
	}
	if (found) {
		cout << cnt;
	}
	else {
		cout << -1;
	}
}