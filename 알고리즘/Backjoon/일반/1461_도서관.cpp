#include <iostream>
#include <algorithm>
using namespace std;

int N, M, book[10001], zero, ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> book[i];
	}
	sort(book, book + N + 1);
	for (int i = 0; i <= N; i++) {
		if (book[i] == 0) {
			zero = i;
			break;
		}
	}

	for (int i = 0; i < zero; i += M) {
		ans += abs(book[i] * 2);
	}
	for (int i = N; i > zero; i -= M) {
		ans += book[i] * 2;
	}

	if (abs(book[0]) >= abs(book[N])) {
		ans -= abs(book[0]);
	}
	else {
		ans -= abs(book[N]);
	}
	cout << ans;
	return 0;
}