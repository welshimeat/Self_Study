#include <stdio.h>
#include <stdlib.h>

int** P;	//P배열을 order함수 안에서 인자로 받지 않으므로 전역변수로 선언

int minmult(int n, const int* d, int** P) {
	int i, j, k, diagonal, temp;
	int** M;
	M = (int**)malloc(n * sizeof(int*)); //M 동적할당
	for (i = 0; i < n; i++){
		M[i] = (int*)malloc(n * sizeof(int)); // M의 2차원 배열 동적할당
		M[i][i] = 0; //M의 i,i 값을 0으로 초기화
	}
	for(diagonal = 1; diagonal <= n-1; diagonal++)
		for (i = 0; i < n - diagonal; i++) {
			j = i + diagonal;
			temp = M[i][i] + M[i + 1][j] + d[i] * d[i + 1] * d[j + 1]; //최솟값을 찾기 위한 비교를 위해 k=i일때의 값을 temp에 미리 부여
			P[i][j] = i;	//위와 같은 이유로 P[i][j]의 값을 i로 부여
			for (k = i; k <= j - 1; k++){
				M[i][j] = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
				if (M[i][j] > temp) {	//k=i의 값이 저장된 temp보다 더 크다면 최솟값이 아니므로 M[i][j] = temp
					M[i][j] = temp;
				}	
				else {	//k=i의 값을 저장한 temp보다 더 작거나 같다면 최솟값이거나 같으므로 temp = M[i][j]
					temp = M[i][j];
					P[i][j] = k;	//최솟값이 바뀌었으므로 P[i][j]의 값을 k로 변경
				}
			}
		}
	return M[0][n-1];	//배열은 0부터 시작하므로 M[0][n-1]
}

void order(int i, int j) {
	int k;
	if (i == j) printf("A%d", i);
	else {
		k = P[i-1][j-1]+1; //P배열은 0부터 시작하므로 i-1,j-1로 하고, P안의 값도 첨자의 값을 나타내므로 실제값인 +1을 해 줌
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}

int main() {
	int n,i;
	int* d;
	
	printf("행렬의 갯수를 입력하세요 : \n");
	scanf("%d", &n);
	
	
	d = (int*)malloc((n + 1) * sizeof(int));	//D배열 동적할당
	P = (int**)malloc(n * sizeof(int*));	//P 동적할당
	for (i = 0; i < n; i++) 
		P[i] = (int*)malloc(n * sizeof(int));	//P 2차원 배열 동적할당

	printf("첫 행렬의 행을 입력하세요 : \n");
	scanf("%d",d);
	printf("다음 행렬의 열들을 차례대로 입력하세요 : \n");
	for (i = 1; i < n + 1; i++) {
		scanf("%d", d + i);
	}
	
	printf("M[1][%d] = %d\n", n, minmult(n, d, P));
	order(1, 6);
}