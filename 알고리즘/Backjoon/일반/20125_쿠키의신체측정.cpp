#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x, y, t;
	char a[1001][1001];
	bool flag = true;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		if (flag) {
			for (int j = 1; j <= N; j++) {
				if (a[i][j] == '*') {
					x = i + 1;
					y = j;
					flag = false;
					cout << x << " " << y << endl;
					break;
				}
			}
		}
		else break;
	}
	
	for (int i = 1; i <= y; i++) {
		if (a[x][i] == '*') {
			cout << y - i << " ";
			break;
		}
	}
	for (int i = N; i >= y; i--) {
		if (a[x][i] == '*') {
			cout << i - y << " ";
			break;
		}
	}
	for (int i = N; i >= x; i--) {
		if (a[i][y] == '*') {
			t = i;
			cout << i - x << " ";
			break;
		}
	}
	for (int i = N; i >= t; i--) {
		if (a[i][y-1] == '*') {
			cout << i - t << " ";
			break;
		}
	}
	for (int i = N; i >= t; i--) {
		if (a[i][y + 1] == '*') {
			cout << i - t << " ";
			break;
		}
	}
	
	return 0;
}