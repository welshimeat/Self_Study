#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int, int>> q;
int N, M, Hx, Hy, Ex, Ey, map[1001][1001], visited[1001][1001][2],
direction_x[4] = { 1, -1, 0, 0 }, direction_y[4] = { 0, 0, 1, -1 };
void bfs();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	if (map[Hx][Hy] == 1 || map[Ex][Ey] == 1) {
		cout << -1 << '\n';
		return 0;
	}

	bfs();

	return 0;
}

void bfs() {
	int x, y, isJump, d;
	bool found = false;

	q.push({ Hx, Hy, 0, 0 });
	visited[Hx][Hy][0] = -1;
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		isJump = get<2>(q.front());
		d = get<3>(q.front());
		q.pop();
		if (x == Ex && y == Ey) {
			found = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x > 0 && new_x <= N && new_y > 0 && new_y <= M) {
				if (!map[new_x][new_y] && !visited[new_x][new_y][isJump] || d + 1 < visited[new_x][new_y][isJump]) {
					q.push({ new_x , new_y, isJump, d + 1 });
					visited[new_x][new_y][isJump] = d + 1;
				}
				else if (!isJump && map[new_x][new_y] && !visited[new_x][new_y][1] || d + 1 < visited[new_x][new_y][1]) {
					q.push({ new_x , new_y, 1, d + 1 });
					visited[new_x][new_y][1] = d + 1;
				}
			}
		}
	}
	if (found) {
		cout << d << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}