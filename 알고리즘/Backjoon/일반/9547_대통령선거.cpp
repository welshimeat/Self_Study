#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main() {
	int T, C, V, *selected, ** candidate, first[2] = { 0, -1 }, second[2] = { 0, -1 };

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &C, &V);
		selected = new int[C] {};
		candidate = new int*[V];
		for (int j = 0; j < V; j++) {
			candidate[j] = new int[C];
		}
		for (int j = 0; j < V; j++) {
			for (int k = 0; k < C; k++) {
				scanf("%d", &candidate[j][k]);
				if (k == 0) {
					selected[candidate[j][0] - 1]++;
				}
			}
		}
		for (int j = 0; j < C; j++) {
			if (selected[j] > second[1]) {
				if (selected[j] > first[1]) {
					second[0] = first[0];
					second[1] = first[1];
					first[0] = j + 1;
					first[1] = selected[j];
				}
				else {
					second[0] = j + 1;
					second[1] = selected[j];
				}
			}
		}
		if (first[1] > V / 2) {
			printf("%d 1\n", first[0]);
			first[1] = -1;
			second[1] = -1;
			continue;
		}
		for (int j = 0; j < V; j++) {
			if (candidate[j][0] == first[0] || candidate[j][0] == second[0]) {
				continue;
			}
			for (int k = 1; k < C; k++) {
				if (candidate[j][k] == first[0]) {
					first[1]++;
					break;
				}
				else if (candidate[j][k] == second[0]) {
					second[1]++;
					break;
				}
			}
		}
		if (first[1] > second[1]) {
			printf("%d 2\n", first[0]);
		}
		else {
			printf("%d 2\n", second[0]);
		}
		first[1] = -1;
		second[1] = -1;
	}
	return 0;
}