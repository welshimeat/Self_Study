#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, cr[11] = { 0 }, num, location, cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num >> location;
		if (location == 1) {
			if (cr[num] == -1) cnt++;
			cr[num] = 1;
		}
		else {
			if (cr[num] == 1) cnt++;
			cr[num] = -1;
		}
	}
	cout << cnt;
	return 0;
}