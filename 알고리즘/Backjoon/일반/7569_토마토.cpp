#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M, N, H, tomato[100][100][100], visited[100][100][100], ripen,
direction_h[6] = { 1, -1, 0, 0, 0, 0 }, direction_n[6] = { 0, 0, 1, -1, 0, 0 }, direction_m[6] = { 0, 0, 0, 0, 1, -1 };
queue<tuple<int, int, int, int>> q;
int bfs();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 0) ripen++;
				else if (tomato[i][j][k] == 1) {
					visited[i][j][k] = 1;
					q.push({ i, j, k, 0 });
				}
			}
		}
	}

	cout << bfs() << '\n';

	return 0;
}

int bfs() {
	int cnt = 0;

	while (!q.empty()) {
		int h = get<0>(q.front());
		int n = get<1>(q.front());
		int m = get<2>(q.front());
		cnt = get<3>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++) {
			int new_h = h + direction_h[i];
			int new_n = n + direction_n[i];
			int new_m = m + direction_m[i];
			if (new_h >= 0 && new_h < H && new_n >= 0 && new_n < N && new_m >= 0 && new_m < M && !visited[new_h][new_n][new_m] && tomato[new_h][new_n][new_m] == 0) {
				ripen--;
				tomato[new_h][new_n][new_m] = 1;
				visited[new_h][new_n][new_m] = 1;
				q.push({ new_h, new_n, new_m, cnt + 1 });
			}
		}
	}
	if (ripen != 0) {
		return -1;
	}
	else return cnt;

}