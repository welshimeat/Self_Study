#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int row, column, N, shop[101][2], x, y, total = 0;

	cin >> row >> column >> N;
	for (int i = 1; i <= N; i++) {
		cin >> shop[i][0] >> shop[i][1];
	}
	cin >> x >> y;

	for (int i = 1; i <= N; i++) {
		if (shop[i][0] == x) {
			total += abs(shop[i][1] - y);
		}
		else if (shop[i][0] == 1 || shop[i][0] == 2) {
			if (x == 1 || x == 2) {
				if (y + shop[i][1] <= 2 * row - y - shop[i][1]) {
					total += y + column + shop[i][1];
				}
				else {
					total += (row - y) + column + (row - shop[i][1]);
				}
			}
			else {
				if (shop[i][0] == 1) {
					if (x == 3) {
						total += y + shop[i][1];
					}
					else {
						total += y + row - shop[i][1];
					}
				}
				else {
					if (x == 3) {
						total += column - y + shop[i][1];
					}
					else {
						total += column - y + row - shop[i][1];
					}
				}
			}
		}
		else {
			if (x == 3 || x == 4) {
				if (y + shop[i][1] >= 2 * column - y - shop[i][1]) {
					total += y + row + shop[i][1];
				}
				else {
					total += (column - y) + row + (column - shop[i][1]);
				}
			}
			else {
				if (shop[i][0] == 3) {
					if (x == 1) {
						total += y + shop[i][1];
					}
					else {
						total += y + column - shop[i][1];
					}
				}
				else {
					if (x == 1) {
						total += row - y + shop[i][1];
					}
					else {
						total += row - y + column - shop[i][1];
					}
				}
			}
		}
	}
	cout << total;
	
	return 0;
}