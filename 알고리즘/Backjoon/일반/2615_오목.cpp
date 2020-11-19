#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main() {
	int map[19][19][5] = { 0 }, cnt;
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf("%d", &map[i][j][0]);
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (map[i][j][0] == 0) {
				continue;
			}
			if (map[i][j][1] != -1 && j < 15) {
				for(cnt = 0; cnt < 4; cnt++){
					if (map[i][j + cnt][0] == map[i][j + 1 + cnt][0]) {
						map[i][j + 1 + cnt][1] = -1;
					}
					else {
						break;
					}
				}
				if (cnt == 4) {
					while (j + cnt < 18 && map[i][j + cnt][0] == map[i][j + 1 + cnt][0]) {
						map[i][j + 1 + cnt][1] = -1;
						cnt++;
					}
					if (cnt == 4) {
						if (map[i][j][0] == 1) {
							printf("1\n");
						}
						else {
							printf("2\n");
						}
						printf("%d %d", i+1, j+1);
						return 0;
					}
				}
			}
			if (map[i][j][2] != -1 && i < 15) {
				for (cnt = 0; cnt < 4; cnt++) {
					if (map[i + cnt][j][0] == map[i + 1 + cnt][j][0]) {
						map[i + 1 + cnt][j][2] = -1;
					}
					else {
						break;
					}
				}
				if (cnt == 4) {
					while (i + cnt < 18 && map[i + cnt][j][0] == map[i + 1 + cnt][j][0]) {
						map[i + 1 + cnt][j][2] = -1;
						cnt++;
					}
					if (cnt == 4) {
						if (map[i][j][0] == 1) {
							printf("1\n");
						}
						else {
							printf("2\n");
						}
						printf("%d %d", i+1, j+1);
						return 0;
					}
				}
			}
			if (map[i][j][3] != -1 && i < 15 && j < 15) {
				for (cnt = 0; cnt < 4; cnt++) {
					if (map[i + cnt][j + cnt][0] == map[i + 1 + cnt][j + 1 + cnt][0]) {
						map[i + 1 + cnt][j + 1 + cnt][3] = -1;
					}
					else {
						break;
					}
				}
				if (cnt == 4) {
					while (i + cnt < 18 && j + cnt < 18 && map[i + cnt][j + cnt][0] == map[i + 1 + cnt][j + 1 + cnt][0]) {
						map[i + 1 + cnt][j + 1 + cnt][3] = -1;
						cnt++;
					}
					if (cnt == 4) {
						if (map[i][j][0] == 1) {
							printf("1\n");
						}
						else {
							printf("2\n");
						}
						printf("%d %d", i+1, j+1);
						return 0;
					}
				}
			}
			if (map[i][j][4] != -1 && i < 15 && j > 3) {
				for (cnt = 0; cnt < 4; cnt++) {
					if (map[i + cnt][j - cnt][0] == map[i + 1 + cnt][j - 1 - cnt][0]) {
						map[i + 1 + cnt][j - 1 - cnt][4] = -1;
					}
					else {
						break;
					}
				}
				if (cnt == 4) {
					while (i + cnt < 18 && j - cnt > 0 && map[i + cnt][j - cnt][0] == map[i + 1 + cnt][j - 1 - cnt][0]) {
						map[i + 1 + cnt][j - 1 - cnt][4] = -1;
						cnt++;
					}
					if(cnt == 4) {
						if (map[i + cnt][j - cnt][0] == 1) {
							printf("1\n");
						}
						else {
							printf("2\n");
						}
						printf("%d %d", i+cnt+1, j-cnt+1);
						return 0;
					}
				}
			}
		}
	}
	printf("0");
	return 0;
}