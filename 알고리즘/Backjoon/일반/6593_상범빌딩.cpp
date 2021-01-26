#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

void bfs(int l, int r, int c);
int L, R, C, departure[3], destination[3], visited[30][30][30],
	direction_l[6] = {0, 0, 0, 0, 1, -1}, direction_r[6] = {0, 0, 1, -1, 0, 0}, direction_c[6] = {1, -1, 0, 0, 0, 0};
char building[30][30][30];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	while (1) {
		cin >> L >> R >> C;
		if (L == 0) {
			break;
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S') {
						departure[0] = i;
						departure[1] = j;
						departure[2] = k;
					}
					else if (building[i][j][k] == 'E') {
						destination[0] = i;
						destination[1] = j;
						destination[2] = k;
					}
				}
			}
		}
		bfs(departure[0], departure[1], departure[2]);
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}

void bfs(int l, int r, int c) {
	queue<pair<int, pair<int, pair<int, int>>>> q;
	int time;
	bool found = false;

	q.push({ l, {r, {c, 0} } });
	while (!q.empty()) {
		l = q.front().first;
		r = q.front().second.first;
		c = q.front().second.second.first;
		time = q.front().second.second.second;
		q.pop();
		if (l == destination[0] && r == destination[1] && c == destination[2]) {
			found = true;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int temp_l = l + direction_l[i],
				temp_r = r + direction_r[i],
				temp_c = c + direction_c[i];

			if (temp_l >= 0 && temp_l < L && temp_r >= 0 && temp_r < R && temp_c >= 0 && temp_c < C &&
				building[temp_l][temp_r][temp_c] != '#'
				&& visited[temp_l][temp_r][temp_c] == 0) {
				q.push({ temp_l, {temp_r, {temp_c, time + 1} } });
				visited[temp_l][temp_r][temp_c] = 1;
			}
		}
	}

	if (found) {
		cout << "Escaped in " << time << " minute(s)." << '\n';
	}
	else {
		cout << "Trapped!" << '\n';
	}
}