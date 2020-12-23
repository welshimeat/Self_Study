#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int R, C, T, map[51][51] = { 0 }, temp[51][51] = { 0 }, top_y, down_y, total = 0, spread;
	
	// �Է�
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];
			temp[i][j] = map[i][j];
		}
	}
	// ����û���� ��ġ
	for (int i = 1; i < C; i++) {
		if (map[i][1] == -1) {
			top_y = i;
			down_y = i + 1;
			break;
		}
	}

	for (int i = 0; i < T; i++) {
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				// �̼����� Ȯ��
				if (temp[j][k] > 4) {
					spread = temp[j][k] / 5;
					// ���� Ȯ��
					if (k > 1 && temp[j][k - 1] != -1) {
						map[j][k - 1] += spread;
						map[j][k] -= spread;
					}
					// ������ Ȯ��
					if (k < C) {
						map[j][k + 1] += spread;
						map[j][k] -= spread;
					}
					// �Ʒ� Ȯ��
					if (j > 1 && temp[j - 1][k] != -1) {
						map[j - 1][k] += spread;
						map[j][k] -= spread;;
					}
					// �� Ȯ��
					if (j < R && temp[j + 1][k] != -1) {
						map[j + 1][k] += spread;
						map[j][k] -= spread;
					}
				}
			}
		}
		// ����
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				temp[j][k] = map[j][k];
			}
		}

		// top && down ������
		temp[top_y][2] = 0;
		temp[down_y][2] = 0;
		for (int j = 3; j <= C; j++) {
			temp[top_y][j] = map[top_y][j - 1];
			temp[down_y][j] = map[down_y][j - 1];
		}

		// top ����
		for (int j = top_y; j >= 2; j--) {
			temp[j - 1][C] = map[j][C];
		}
		// top ����
		for (int j = C; j >= 2; j--) {
			temp[1][j - 1] = map[1][j];
		}
		// top �Ʒ���
		for (int j = 1; j <= top_y - 2; j++) {
			temp[j + 1][1] = map[j][1];
		}

		// down �Ʒ���
		for (int j = down_y; j <= R - 1; j++) {
			temp[j + 1][C] = map[j][C];
		}
		// down ����
		for (int j = C; j >= 2; j--) {
			temp[R][j - 1] = map[R][j];
		}
		// down ����
		for (int j = R; j >= down_y + 2; j--) {
			temp[j - 1][1] = map[j][1];
		}
		
		// ����
		for (int j = 1; j <= R; j++) {
			for (int k = 1; k <= C; k++) {
				map[j][k] = temp[j][k];
			}
		}
	}
	// �̼����� �� ���
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] != -1) {
				total += map[i][j];
			}
		}
	}
	cout << total;
	return 0;
}