#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main() {
	int N, n, **map, x, y, now = 0, n_x, n_y;

	scanf("%d %d", &N, &n);
	map = new int*[N];
	for (int i = 0; i < N; i++)
		map[i] = new int[N] {};
	x = N / 2;
	y = N / 2;

	for (int i = 1; i <= N * N; i++) {
		map[x][y] = i;
		if (i == n) {
			n_x = x + 1;
			n_y = y + 1;
		}
		if (now == 0) {
			if (map[x - 1][y] == 0) {
				x = x - 1;
				now++;
			}
			else {
				y = y - 1;
			}
		}
		else if (now == 1) {
			if (map[x][y + 1] == 0) {
				y = y + 1;
				now++;
			}
			else {
				x = x - 1;
			}
		}
		else if (now == 2) {
			if (map[x + 1][y] == 0) {
				x = x + 1;
				now++;
			}
			else {
				y = y + 1;
			}
		}
		else if (now == 3) {
			if (map[x][y - 1] == 0) {
				y = y - 1;
				now = 0;
			}
			else {
				x = x + 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("%d %d", n_x, n_y);
	return 0;
}