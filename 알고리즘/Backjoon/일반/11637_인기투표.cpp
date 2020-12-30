#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n, vote[11] = { 0 }, index, total, max;
	bool flag;

	cin >> T;
	for (int i = 0; i < T; i++) {
		total = 0;
		cin >> n;
		flag = true;
		for (int j = 1; j <= n; j++) {
			cin >> vote[j];
			total += vote[j];
		}
		max = *max_element(vote + 1, vote + 1 + n);
		for (int j = 1; j <= n; j++) {
			if (flag && vote[j] == max) {
				index = j;
				flag = false;
			}
			else if (!flag && vote[j] == max) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			if (max > total / 2) {
				cout << "majority winner " << index << endl;
			}
			else {
				cout << "minority winner " << index << endl;
			}
		}
		else {
			cout << "no winner" << endl;
		}
	}

	

	return 0;
}