#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, C, N;
	char map[200][200];
	int	temp[200][200];

	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O') {
				temp[i][j] = 3;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		if (i % 2 == 1) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (temp[j][k] == i) {
						map[j][k] = '.';
						if (j > 0) {
							map[j - 1][k] = '.';
						}
						if (j < R - 1) {
							map[j + 1][k] = '.';
						}
						if (k > 0) {
							map[j][k - 1] = '.';
						}
						if (k < C - 1) {
							map[j][k + 1] = '.';
						}
					}
				}
			}
		}
		else {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (map[j][k] == '.') {
						map[j][k] = 'O';
						temp[j][k] = i + 3;
					}	
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}

	return 0;
}