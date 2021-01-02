#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a[10], b[10], a_score = 0, b_score = 0;

	for (int i = 1; i <= 9; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 9; i++) {
		cin >> b[i];
	}

	for (int i = 1; i <= 9; i++) {
		a_score += a[i];
		if (a_score > b_score) {
			cout << "Yes";
			return 0;
		}
		b_score += b[i];
	}
	cout << "No";

	return 0;
}