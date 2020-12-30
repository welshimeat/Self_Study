#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x = 0, y = 0, N, map[3][3] = { 1 }, input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;
			if (map[i][j] == 1) {
				if (i + input < N) {
					map[i + input][j] = 1;
				}
				if (j + input < N) {
					map[i][j + input] = 1;
				}
			}
		}
	}

	if (map[N-1][N-1] == 1) {
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}
	
	return 0;
}
