#pragma warning(disable:4996)
#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> r, c;
	int N, map[9][9];
	bool flag;

	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		flag = true;
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				scanf("%d", &map[j][k]);
			}
		}
		// 가로 세로
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				r.insert(map[j][k]);
				c.insert(map[k][j]);
			}
			if (r.size() != 9 || c.size() != 9) {
				printf("Case %d: INCORRECT\n", i + 1);
				r.clear();
				c.clear();
				flag = false;
				break;
			}
			r.clear();
			c.clear();
		}
		if (!flag) {
			continue;
		}
		// 사각형
		for (int j = 0; j < 3; j++) {
			if (!flag) {
				break;
			}
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					for (int m = 0; m < 3; m++) {
						r.insert(map[j * 3 + l][k * 3 + m]);
					}
				}
				if (r.size() != 9) {
					printf("Case %d: INCORRECT\n", i + 1);
					r.clear();
					flag = false;
					break;
				}
				r.clear();
			}
		}
		if (!flag) {
			continue;
		}
		else {
			printf("Case %d: CORRECT\n", i + 1);
		}
	}
	
	return 0;
}