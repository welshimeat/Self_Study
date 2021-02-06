#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt = 0, dp[50001] = { 0, 1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	for(int i = 2; i <=n; i++){
		dp[i] = 4;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];

	return 0;
}