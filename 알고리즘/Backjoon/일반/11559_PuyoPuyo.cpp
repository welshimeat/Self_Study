#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char map[12][6], cnt, total = 0;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.') {
					cnt = 0;
					for (int k = i - 1; k >= 0; k--) {
						if (map[k][j] == map[i][j]) {
							cnt++;
						}
						else
					}
				}
			}

	}

	return 0;
}