#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, d, t, cnt = 0;

	cin >> n >> d;

	for (int i = 1; i <= n; i++) {
		t = i;
		while (t != 0) {
			if (t % 10 == d) {
				cnt++;
			}
			t /= 10;
		}
	}
	cout << cnt;
	return 0;
}