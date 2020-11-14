#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int size, x_1, y_1, r_1, x_2, y_2, r_2, res;
	double d;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
		d = sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));

		if (d == 0) {
			if (r_1 == r_2) {
				res = -1;
			}
			else {
				res = 0;
			}
		}
		else {
			if (r_1 + r_2 > d && abs(r_1 - r_2) < d) {
				res = 2;
			}
			else if (r_1 + r_2 == d || abs(r_1 - r_2) == d) {
				res = 1;
			}
			else {
				res = 0;
			}
		}
		printf("%d\n", res);
	}
	
	return 0;
}