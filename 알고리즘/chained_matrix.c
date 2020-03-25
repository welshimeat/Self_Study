#include <stdio.h>
#include <stdlib.h>

int** P;	//P�迭�� order�Լ� �ȿ��� ���ڷ� ���� �����Ƿ� ���������� ����

int minmult(int n, const int* d, int** P) {
	int i, j, k, diagonal, temp;
	int** M;
	M = (int**)malloc(n * sizeof(int*)); //M �����Ҵ�
	for (i = 0; i < n; i++){
		M[i] = (int*)malloc(n * sizeof(int)); // M�� 2���� �迭 �����Ҵ�
		M[i][i] = 0; //M�� i,i ���� 0���� �ʱ�ȭ
	}
	for(diagonal = 1; diagonal <= n-1; diagonal++)
		for (i = 0; i < n - diagonal; i++) {
			j = i + diagonal;
			temp = M[i][i] + M[i + 1][j] + d[i] * d[i + 1] * d[j + 1]; //�ּڰ��� ã�� ���� �񱳸� ���� k=i�϶��� ���� temp�� �̸� �ο�
			P[i][j] = i;	//���� ���� ������ P[i][j]�� ���� i�� �ο�
			for (k = i; k <= j - 1; k++){
				M[i][j] = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
				if (M[i][j] > temp) {	//k=i�� ���� ����� temp���� �� ũ�ٸ� �ּڰ��� �ƴϹǷ� M[i][j] = temp
					M[i][j] = temp;
				}	
				else {	//k=i�� ���� ������ temp���� �� �۰ų� ���ٸ� �ּڰ��̰ų� �����Ƿ� temp = M[i][j]
					temp = M[i][j];
					P[i][j] = k;	//�ּڰ��� �ٲ�����Ƿ� P[i][j]�� ���� k�� ����
				}
			}
		}
	return M[0][n-1];	//�迭�� 0���� �����ϹǷ� M[0][n-1]
}

void order(int i, int j) {
	int k;
	if (i == j) printf("A%d", i);
	else {
		k = P[i-1][j-1]+1; //P�迭�� 0���� �����ϹǷ� i-1,j-1�� �ϰ�, P���� ���� ÷���� ���� ��Ÿ���Ƿ� �������� +1�� �� ��
		printf("(");
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}

int main() {
	int n,i;
	int* d;
	
	printf("����� ������ �Է��ϼ��� : \n");
	scanf("%d", &n);
	
	
	d = (int*)malloc((n + 1) * sizeof(int));	//D�迭 �����Ҵ�
	P = (int**)malloc(n * sizeof(int*));	//P �����Ҵ�
	for (i = 0; i < n; i++) 
		P[i] = (int*)malloc(n * sizeof(int));	//P 2���� �迭 �����Ҵ�

	printf("ù ����� ���� �Է��ϼ��� : \n");
	scanf("%d",d);
	printf("���� ����� ������ ���ʴ�� �Է��ϼ��� : \n");
	for (i = 1; i < n + 1; i++) {
		scanf("%d", d + i);
	}
	
	printf("M[1][%d] = %d\n", n, minmult(n, d, P));
	order(1, 6);
}