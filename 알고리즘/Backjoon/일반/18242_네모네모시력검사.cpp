#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, length, x, y;
	char map[100][100];
	bool flag = true;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		if (!flag) {
			break;
		}
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#') {
				x = j, y = i;
				for (int k = M - 1; k > 0; k--) {
					if (map[i][k] == '#') {
						length = k - j + 1;
						break;
					}
				}
				flag = false;
				break;
			}
		}
	}

	if (map[y][x + length / 2] == '.') {
		cout << "UP";
	}
	else if (map[y + length / 2][x] == '.') {
		cout << "LEFT";
	}
	else if (map[y + length - 1][x + length / 2] == '.') {
		cout << "DOWN";
	}
	else {
		cout << "RIGHT";
	}


	return 0;
}