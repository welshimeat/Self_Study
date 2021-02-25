#include <iostream>
#include <algorithm>
using namespace std;

int dp[10003], juice[10003], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> juice[i];
	}
	dp[1] = juice[1];
	dp[2] = juice[1] + juice[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3] + juice[i - 1]) + juice[i];
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n];

	return 0;
}