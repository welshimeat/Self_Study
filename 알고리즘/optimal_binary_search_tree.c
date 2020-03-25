#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

float sum(const float* p,int i,int j) {
	float res = 0;
	for (i; i <= j; i++)
		res += p[i];
	return res;
}

void optsearchtree(int n, const float *p, float *minavg, int** R) {
	int i, j, k, diagonal;
	float** A, temp;
	A = (float **)malloc((n + 2) * sizeof(float*));
	for (i = 1; i < n+2; i++) {
		A[i] = (float*)malloc(n * sizeof(float));
	}
	for (i = 1; i <= n; i++) {
		A[i][i - 1] = 0;
		A[i][i] = p[i];
		R[i][i] = i;
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0;
	R[n + 1][n] = 0;

	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			temp = A[i][i-1] + A[i + 1][j] + sum(p,i,j);
			R[i][j] = i;
			for (k = i; k <= j; k++) {
				A[i][j] = A[i][k-1] + A[k + 1][j] + sum(p, i, j);
				if (A[i][j] >= temp) {
					A[i][j] = temp;
				}
				else {
					temp = A[i][j];
					R[i][j] = k;
				}
			}
		}
	printf("A�迭\n");
	for (i = 1; i <= 5; i++) {
		printf("\n");
		for (j = 0; j <= 4; j++)
			if (A[i][j] < 0)
				printf("     ");
			else
				printf("%.2f ", A[i][j]);
	}
	printf("\nR�迭\n");
	for (i = 1; i <= 5; i++) {
		printf("\n");
		for (j = 0; j <= 4; j++)
			if (A[i][j] < 0)
				printf("  ");
			else
				printf("%d ", R[i][j]);
	}
	*minavg = A[1][n];
}

int main() {
	int n, i;
	float* p,minavg;
	int** R;
	minavg = 0;

	printf("KEY�� ������ �Է��ϼ��� : \n");
	scanf("%d", &n);

	p = (float*)malloc((n + 1) * sizeof(float));
	R = (int**)malloc((n + 2) * sizeof(int*));
	for (i = 1; i < n+2; i++)
		R[i] = (int*)malloc((n + 1) * sizeof(int));

	printf("�� KEY�� Ȯ���� ���ʴ��� �Է��ϼ��� : \n");
	for (i = 1; i <= n; i++) {
		scanf("%f", p + i);
	}

	optsearchtree(n, p, &minavg, R);
	printf("\nA[1][%d] = %f\n", n, minavg);
	printf("R[1][%d] = %d\n", n, R[1][n]);
}
