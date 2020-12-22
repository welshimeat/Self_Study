#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, bug[21] = { 0, 1, 2, 4, 7};
	
	cin >> N;

	if (N <= 3) {
		cout << bug[N];
	}
	else {
		for (int i = 5; i <= N; i++) {
			if (i % 2 == 1) {
				bug[i] = bug[i - 1] * 2;
			}
			else {
				bug[i] = bug[i - 1] * 2 - bug[i - 4] - bug[i - 5];
			}
		}
		cout << bug[N];
	}
	

	return 0;
}