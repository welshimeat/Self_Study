#include <iostream>
#include <algorithm>
using namespace std;

int dp[1500002], highest;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, t, p;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t >> p;
		highest = max(highest, dp[i]);
		if (i + t <= N + 1) {
			dp[i + t] = max(highest + p, dp[i + t]);
		}
	}
	cout << max(dp[N+1], highest);

	return 0;
}