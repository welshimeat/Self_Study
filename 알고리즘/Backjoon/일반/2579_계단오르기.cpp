#include <iostream>
#include <algorithm>
using namespace std;
int jumpUsed[300], jumpNotUsed[300];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> jumpNotUsed[i];
		jumpUsed[i] = jumpNotUsed[i];
	}
	if (N == 1) {
		cout << jumpNotUsed[0];
		return 0;
	}
	else if (N == 2) {
		cout << jumpNotUsed[0] + jumpNotUsed[1];
		return 0;
	}
	else {
		jumpNotUsed[1] += jumpUsed[0];
		for (int i = 2; i < N; i++) {
			jumpUsed[i] += max(jumpUsed[i - 2], jumpNotUsed[i-2]);
			jumpNotUsed[i] += jumpUsed[i - 1];
		}
	}
	cout << max(jumpUsed[N - 1], jumpNotUsed[N - 1]);

	return 0;
}