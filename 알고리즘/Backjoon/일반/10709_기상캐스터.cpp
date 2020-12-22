#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int H, W;
	char map[100][100];

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'c') {
				cout << 0 << " ";
			}
			else {
				for (int k = j-1; k >= -1; k--) {
					if (k == -1) {
						cout << -1 << " ";
					}
					else {
						if (map[i][k] == 'c') {
							cout << j - k << " ";
							break;
						}
					}
				}
			}
		}
		cout << endl;
	}
	
	return 0;
}