#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main() {
	int R, C, k, br, bc, sr, sc, dr, dc, direction[4], now = 0, i;

	scanf("%d %d %d", &R, &C, &k);
	int** map = new int*[R];
	for (i = 0; i < R; i++) {
		map[i] = new int[C] {};
	}

	for (i = 0; i < k; i++) {
		scanf("%d %d", &br, &bc);
		map[br][bc] = 1;
	}
	scanf("%d %d %d %d %d %d", &sr, &sc, direction, direction + 1, direction + 2, direction + 3);

	while (1) {
		map[sr][sc] = 1;
	
		for (i = 0; i < 4; i++) {
			/*for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					printf("%d ", map[j][k]);
				}
				printf("\n");
			}
			printf("\n");*/
			
			switch (direction[now]) {
				case 1: dr = sr - 1; dc = sc; break;
				case 2: dr = sr + 1; dc = sc; break;
				case 3: dc = sc - 1; dr = sr; break;
				case 4: dc = sc + 1; dr = sr; 
			}
			if (dr >= 0 && dr <= R-1 && dc >= 0 && dc <= C-1 && map[dr][dc] != 1) {
				sr = dr;
				sc = dc;
				break;
			}
			else {
				now = (now + 1) % 4;
			}
		}
		if (i == 4) {
			break;
		}
	}
	printf("%d %d", sr, sc);
	return 0;
}