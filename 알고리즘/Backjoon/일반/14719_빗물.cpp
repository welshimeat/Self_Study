#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int H, W, block[501], cnt = 0, current, leftMax, rightMax;

	cin >> H >> W;
	for (int i = 1; i <= W; i++) {
		cin >> block[i];
	}

	for (int i = 2; i <= W - 1; i++) {
		leftMax = 0;
		rightMax = 0;
		current = block[i];
		for (int j = i - 1; j >= 1; j--) {
			if (leftMax < block[j]) {
				leftMax = block[j];
			}
		}
		for (int j = i + 1; j <= W; j++) {
			if (rightMax < block[j]) {
				rightMax = block[j];
			}
		}
		if (current < leftMax && current < rightMax) {
			if (leftMax >= rightMax) {
				cnt += rightMax - current;
			}
			else {
				cnt += leftMax - current;
			}
		}
		
	}
	cout << cnt;

	return 0;
}