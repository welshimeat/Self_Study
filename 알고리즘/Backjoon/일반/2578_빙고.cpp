#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int map[5][5], check[5][5] = { 0 }, num, x, y, cnt = 0;
	bool bingo, crossL = false, crossR = false, checked;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			checked = false;
			for (int a = 0; a < 5; a++) {
				for (int b = 0; b < 5; b++) {
					if (map[a][b] == num) {
						x = a;
						y = b;
						check[a][b] = 1;
						checked = true;
						break;
					}
				}
				if (checked) break;
			}

			bingo = true;
			for (int a = 0; a < 5; a++) {
				if (!check[x][a]) {
					bingo = false;
					break;
				}
			}
			if (bingo) cnt++;
			bingo = true;
			for (int a = 0; a < 5; a++) {
				if (!check[a][y]) {
					bingo = false;
					break;
				}
			}
			if (bingo) cnt++;
			if (x == y && !crossL) {
				bingo = true;
				for (int a = 0; a < 5; a++) {
					if (!check[a][a]) {
						bingo = false;
						break;
					}
				}
				if (bingo) {
					crossL = true;
					cnt++;
				}
			}
			if (x + y == 4 && !crossR) {
				bingo = true;
				for (int a = 0; a < 5; a++) {
					if (!check[a][4 - a]) {
						bingo = false;
						break;
					}
				}
				if (bingo) {
					crossR = true;
					cnt++;
				}
			}
			if (cnt >= 3) {
				cout << i * 5 + j + 1 << '\n';
				return 0;
			}
		}
	}
	return 0;
}