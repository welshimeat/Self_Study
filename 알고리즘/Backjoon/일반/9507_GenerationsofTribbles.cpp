#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long koong[68] = { 1, 1, 2, 4 };
	int t, n;

	cin >> t;

	for (int i = 4; i <= 67; i++) {
		koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
	}
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << koong[n] << endl;
	}
	return 0;
}