#include <iostream>
#include <math.h>
using namespace std;
long long int dp[101][10], sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	
	cin >> N;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i-1][1];
		dp[i][9] = dp[i-1][8];
		for (int j = 1; j < 9; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	for (int i = 0; i < 9; i++) {
		sum += dp[N][i];
	}
	sum %= 1000000000;
	cout << sum;

	return 0;
}