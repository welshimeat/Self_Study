#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, C, cnt, minX, maxX = 0, minY, maxY = 0;
	char map[10][10], answer[10][10];
	
	cin >> R >> C;
	minY = R-1;
	minX = C-1;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'X') {
				cnt = 0;
				if (i == 0 || map[i - 1][j] == '.') cnt++;
				if (i == R - 1 || map[i + 1][j] == '.') cnt++;
				if (j == 0 || map[i][j - 1] == '.') cnt++;
				if (j == C - 1 || map[i][j + 1] == '.') cnt++;
				if (cnt >= 3) {
					answer[i][j] = '.';
				}
				else {
					answer[i][j] = 'X';
					if (i < minY) minY = i;
					if (i > maxY) maxY = i;
					if (j < minX) minX = j;
					if (j > maxX) maxX = j;
				}
			}
			else {
				answer[i][j] = '.';
			}
		}
	}
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			cout << answer[i][j];
		}
		cout << endl;
	}
	return 0;
}