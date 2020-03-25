#include <stdio.h>
#include <stdlib.h>

int threshold = 1;


void matrixmult(int n, int** A, int** B, int** C) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
		}
}// 행렬 곱셈 함수

void matrixsum(int n, int** A, int** B, int** val) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			val[i][j] = 0;
			val[i][j] = A[i][j] + B[i][j];
		}
}// 행렬 덧셈 함수

void matrixsub(int n, int** A, int** B, int** val) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			val[i][j] = 0;
			val[i][j] = A[i][j] - B[i][j];
		}
}// 행렬 뺄셈 함수

void resprint(int n, int** C) {
	for (int i = 0; i < n; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", C[i][j]);
		}
	}
	printf("\n");
}// 행렬 출력 함수

	void strassen(const int n, int** A, int** B, int** C) {
		if (n <= threshold)
			matrixmult(n, A, B, C);
		else {
			int** A11 = (int**)calloc(n / 2, sizeof(int*));
			int** A12 = (int**)calloc(n / 2, sizeof(int*));
			int** A21 = (int**)calloc(n / 2, sizeof(int*));
			int** A22 = (int**)calloc(n / 2, sizeof(int*));
			int** B11 = (int**)calloc(n / 2, sizeof(int*));
			int** B12 = (int**)calloc(n / 2, sizeof(int*));
			int** B21 = (int**)calloc(n / 2, sizeof(int*));
			int** B22 = (int**)calloc(n / 2, sizeof(int*));
			int** C11 = (int**)calloc(n / 2, sizeof(int*));
			int** C12 = (int**)calloc(n / 2, sizeof(int*));
			int** C21 = (int**)calloc(n / 2, sizeof(int*));
			int** C22 = (int**)calloc(n / 2, sizeof(int*));
			int** M1 = (int**)calloc(n / 2, sizeof(int*));
			int** M2 = (int**)calloc(n / 2, sizeof(int*));
			int** M3 = (int**)calloc(n / 2, sizeof(int*));
			int** M4 = (int**)calloc(n / 2, sizeof(int*));
			int** M5 = (int**)calloc(n / 2, sizeof(int*));
			int** M6 = (int**)calloc(n / 2, sizeof(int*));
			int** M7 = (int**)calloc(n / 2, sizeof(int*));
			int** val1 = (int**)calloc(n / 2, sizeof(int*));
			int** val2 = (int**)calloc(n / 2, sizeof(int*));

			for (int i = 0; i < n / 2; i++) {
				A11[i] = (int*)calloc(n / 2, sizeof(int));
				A12[i] = (int*)calloc(n / 2, sizeof(int));
				A21[i] = (int*)calloc(n / 2, sizeof(int));
				A22[i] = (int*)calloc(n / 2, sizeof(int));
				B11[i] = (int*)calloc(n / 2, sizeof(int));
				B12[i] = (int*)calloc(n / 2, sizeof(int));
				B21[i] = (int*)calloc(n / 2, sizeof(int));
				B22[i] = (int*)calloc(n / 2, sizeof(int));
				C11[i] = (int*)calloc(n / 2, sizeof(int));
				C12[i] = (int*)calloc(n / 2, sizeof(int));
				C21[i] = (int*)calloc(n / 2, sizeof(int));
				C22[i] = (int*)calloc(n / 2, sizeof(int));
				M1[i] = (int*)calloc(n / 2, sizeof(int));
				M2[i] = (int*)calloc(n / 2, sizeof(int));
				M3[i] = (int*)calloc(n / 2, sizeof(int));
				M4[i] = (int*)calloc(n / 2, sizeof(int));
				M5[i] = (int*)calloc(n / 2, sizeof(int));
				M6[i] = (int*)calloc(n / 2, sizeof(int));
				M7[i] = (int*)calloc(n / 2, sizeof(int));
				val1[i] = (int*)calloc(n / 2, sizeof(int));
				val2[i] = (int*)calloc(n / 2, sizeof(int));
			} // 2차원 배열 동적할당

			for (int i = 0; i < n / 2; i++)
				for (int j = 0; j < n / 2; j++) {
					A11[i][j] = A[i][j];
					A12[i][j] = A[i][j + n / 2];
					A21[i][j] = A[i + n / 2][j];
					A22[i][j] = A[i + n / 2][j + n / 2];
					B11[i][j] = B[i][j];
					B12[i][j] = B[i][j + n / 2];
					B21[i][j] = B[i + n / 2][j];
					B22[i][j] = B[i + n / 2][j + n / 2];
				} // A행렬과 B행렬을 4개의 submatrice로 분할

			matrixsum(n / 2, A11, A22, val1);
			matrixsum(n / 2, B11, B22, val2);
			strassen(n / 2, val1, val2, M1);// M1 재귀 계산

			matrixsum(n / 2, A21, A22, val1);
			strassen(n / 2, val1, B11, M2);// M2 재귀 계산

			matrixsub(n / 2, B12, B22, val1);
			strassen(n / 2, A11, val1, M3);// M3 재귀 계산

			matrixsub(n / 2, B21, B11, val1);
			strassen(n / 2, A22, val1, M4);// M4 재귀 계산

			matrixsum(n / 2, A11, A12, val1);
			strassen(n / 2, val1, B22, M5);// M5 재귀 계산

			matrixsub(n / 2, A21, A11, val1);
			matrixsum(n / 2, B11, B12, val2);
			strassen(n / 2, val1, val2, M6);// M6 재귀 계산

			matrixsub(n / 2, A12, A22, val1);
			matrixsum(n / 2, B21, B22, val2);
			strassen(n / 2, val1, val2, M7);// M7 재귀 계산

			matrixsum(n / 2, M1, M4, val1);
			matrixsum(n / 2, val1, M7, val2);
			matrixsub(n / 2, val2, M5, C11);// C11 계산

			matrixsum(n / 2, M3, M5, C12);// C12 계산

			matrixsum(n / 2, M2, M4, C21);// C21 계산

			matrixsum(n / 2, M1, M3, val1);
			matrixsum(n / 2, val1, M6, val2);
			matrixsub(n / 2, val2, M2, C22);// C22 계산

			for (int i = 0; i < n / 2; i++)
				for (int j = 0; j < n / 2; j++) {
					C[i][j] = C11[i][j];
					C[i][j + n / 2] = C12[i][j];
					C[i + n / 2][j] = C21[i][j];
					C[i + n / 2][j + n / 2] = C22[i][j];
				}// C11,C12,C21,C22를 다시 C에 복사

			for (int i = 0; i < n / 2; i++) {
				free(A11[i]);
				free(A12[i]);
				free(A21[i]);
				free(A22[i]);
				free(B11[i]);
				free(B12[i]);
				free(B21[i]);
				free(B22[i]);
				free(C11[i]);
				free(C12[i]);
				free(C21[i]);
				free(C22[i]);
				free(M1[i]);
				free(M2[i]);
				free(M3[i]);
				free(M4[i]);
				free(M5[i]);
				free(M6[i]);
				free(M7[i]);
				free(val1[i]);
				free(val2[i]);
			}
			free(A11);
			free(A12);
			free(A21);
			free(A22);
			free(B11);
			free(B12);
			free(B21);
			free(B22);
			free(C11);
			free(C12);
			free(C21);
			free(C22);
			free(M1);
			free(M2);
			free(M3);
			free(M4);
			free(M5);
			free(M6);
			free(M7);
			free(val1);
			free(val2);
				
		}
		
	}

	int main() {
		const int n = 4;
		int** A = (int**)calloc(n, sizeof(int*));
		int** B = (int**)calloc(n, sizeof(int*));
		int** C = (int**)calloc(n, sizeof(int*));
		for (int i = 0; i < n; i++) {
			A[i] = (int*)calloc(n, sizeof(int));
			B[i] = (int*)calloc(n, sizeof(int));
			C[i] = (int*)calloc(n, sizeof(int));
		}// A,B,C 2차원 배열 동작할당

		A[0][0] = 0;
		A[0][1] = 1;
		A[0][2] = 0;
		A[0][3] = 4;
		A[1][0] = 7;
		A[1][1] = 1;
		A[1][2] = 3;
		A[1][3] = 1;
		A[2][0] = 7;
		A[2][1] = 2;
		A[2][2] = 6;
		A[2][3] = 5;
		A[3][0] = 9;
		A[3][1] = 1;
		A[3][2] = 1;
		A[3][3] = 7;

		B[0][0] = 2;
		B[0][1] = 6;
		B[0][2] = 9;
		B[0][3] = 5;
		B[1][0] = 0;
		B[1][1] = 3;
		B[1][2] = 2;
		B[1][3] = 3;
		B[2][0] = 4;
		B[2][1] = 6;
		B[2][2] = 6;
		B[2][3] = 3;
		B[3][0] = 1;
		B[3][1] = 2;
		B[3][2] = 1;
		B[3][3] = 2;

		strassen(n, A, B, C);
		resprint(n,C);

		for (int i = 0; i < n; i++) {
			free(A[i]);
			free(B[i]);
			free(C[i]);
		}
		free(A);
		free(B);
		free(C);// 동적 할당 해제
	}
