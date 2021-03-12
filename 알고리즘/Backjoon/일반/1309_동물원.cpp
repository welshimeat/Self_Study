#include <iostream>
using namespace std;
int dp[100001] = { 0, 3, 7, 17};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = 2 * dp[i - 1] + dp[i - 2];
		dp[i] %= 9901;
	}
	cout << dp[N];

	return 0;
}