#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int N, M, security[100000], high = 1, low = 0, mid, sum, res;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> security[i];
		if (security[i] > high) {
			high = security[i];
		}
	}
	high *= M;
	while (low <= high) {
		mid = (low + high) / 2;
		sum = 0;
		for (int i = 0; i < N; i++) {
			sum += mid / security[i];
		}
		if (sum < M) {
			low = mid + 1;
		}
		else {
			res = mid;
			high = mid - 1;
		}
	}
	cout << res;

	return 0;
}