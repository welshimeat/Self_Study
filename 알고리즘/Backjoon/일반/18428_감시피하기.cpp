#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, direction_x[4] = { 0, 0, 1, -1 }, direction_y[4] = { 1, -1, 0, 0 };
	char map[6][6];
	vector<pair<int, int>> teacher;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T') {
				teacher.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < N * N; i++) {
		for (int j = i + 1; j < N * N; j++) {
			for (int k = j + 1; k < N * N; k++) {
				int o1_x = i / N, o1_y = i % N,
					o2_x = j / N, o2_y = j % N,
					o3_x = k / N, o3_y = k % N;
				if (map[o1_x][o1_y] == 'T' || map[o1_x][o1_y] == 'S' ||
					map[o2_x][o2_y] == 'T' || map[o2_x][o2_y] == 'S' ||
					map[o3_x][o3_y] == 'T' || map[o3_x][o3_y] == 'S') {
					continue;
				}
				map[o1_x][o1_y] = 'O';
				map[o2_x][o2_y] = 'O';
				map[o3_x][o3_y] = 'O';
				bool flag = true;
				for (int l = 0; l < teacher.size(); l++) {
					int x = teacher[l].first;
					int y = teacher[l].second;
					for (int m = 0; m < 4; m++) {
						int new_x = x + direction_x[m];
						int new_y = y + direction_y[m];
						while (1) {
							if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
								if (map[new_x][new_y] == 'O' || map[new_x][new_y] == 'T') {
									break;
								}
								else if (map[new_x][new_y] == 'S') {
									flag = false;
									break;
								}
								else {
									new_x += direction_x[m];
									new_y += direction_y[m];
								}
							}
							else {
								break;
							}
						}
						if (!flag) break;
					}
					if (!flag) break;
				}
				if (flag) {
					cout << "YES" << '\n';
					return 0;
				}
				map[o1_x][o1_y] = NULL;
				map[o2_x][o2_y] = NULL;
				map[o3_x][o3_y] = NULL;
			}
		}
	}
	cout << "NO" << '\n';
	return 0;
}