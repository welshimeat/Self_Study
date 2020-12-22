#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, ** dice, bottom, up, max, total = 0, answer = 0;

	cin >> N;
	dice = new int*[N];
	for (int i = 0; i < N; i++) {
		dice[i] = new int[6];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dice[i][j];
		}
	}
	
	for (int i = 1; i <= 6; i++) {
		up = i;
		for (int j = 0; j < N; j++) {
			max = 0;
			for (int k = 0; k < 6; k++) {
				if (dice[j][k] == up) {
					bottom = up;
					switch (k) {
					case 0: up = dice[j][5]; break;
					case 1: up = dice[j][3]; break;
					case 2: up = dice[j][4]; break;
					case 3: up = dice[j][1]; break;
					case 4: up = dice[j][2]; break;
					case 5: up = dice[j][0]; break;
					}
					break;
				}
			}
			for (int k = 0; k < 6; k++) {
				if (dice[j][k] != up && dice[j][k] != bottom) {
					if (dice[j][k] > max) {
						max = dice[j][k];
					}
				}
			}
			total += max;
		}
		if (total > answer) {
			answer = total;
		}
		total = 0;
	}
	cout << answer;
	
	return 0;
}