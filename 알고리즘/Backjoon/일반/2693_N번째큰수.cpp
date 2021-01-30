#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, A[10];

	cin >> T;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> A[j];
		}
		sort(A, A + 10);
		cout << A[7] << '\n';
	}
	return 0;
}