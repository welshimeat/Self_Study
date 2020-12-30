#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, cross[4][2] = { { 0, -1 }, {0, 1}, {-1, 0}, {1, 0} };
	char map[101][101];

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < M; j++) {
			int cnt[4] = { 0 };
			if (map[i][j] == '*') {
				for (int k = 0; k < 4; k++) {
					if (map[i + cross[k][0]][j + cross[k][1]] == '*') {
						cnt[0]++;
					}
						else {
							break;
						}
					}
				}
				
				
				
			}
		}
	}


	return 0;
}
