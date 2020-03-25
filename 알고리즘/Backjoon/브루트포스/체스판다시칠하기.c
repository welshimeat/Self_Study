#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, M, white = 0, black = 0, min = 64, temp;
	scanf("%d %d", &N, &M);
	char m[N][M];
	// char** m = (char**)malloc(N * sizeof(char*));
	// for (int i = 0; i < N; i++)
	// 	m[i] = (char*)malloc(M * sizeof(char));

	char WHITE[8][8] = { 'W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W' };
	char BLACK[8][8] = { 'B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B','B','W','B','W','B','W','B','W','W','B','W','B','W','B','W','B' };

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf(" %c", &m[i][j]);


	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++){
			for (int p = i; p <= i + 7; p++)
				for (int q = j; q <= j + 7; q++) {
					if (m[p][q] != BLACK[p - i][q - j])
						black++;
					else if (m[p][q] != WHITE[p - i][q - j])
						white++;
				}
			if(black >= white) temp = white;
			else temp = black;
			if(min>temp) min = temp;
			black = 0,white = 0;
		}

	printf("%d", min);
}
