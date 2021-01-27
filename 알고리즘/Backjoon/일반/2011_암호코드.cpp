#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input;
	int dp[5000] = { 0 };

	cin >> input;
	if (input.size() == 0 || input[0] == '0') {
		cout << '0' << '\n';
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i < input.size(); i++) {
		if (input[i - 1] == '1' || (input[i - 1] == '2' && input[i] < '7')) {
			if (i == 1) {
				if (input[i] != '0') {
					dp[i] = 2;
				}
				else {
					dp[i] = 1;
				}
				continue;
			}
			if (input[i] != '0') {
				dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000;
			}
			else {
				dp[i] = dp[i - 2];
			}
		}
		else {
			if (input[i] == '0') {
				cout << '0' << '\n';
				return 0;
			}
			dp[i] = (dp[i] + dp[i - 1]) % 1000000;
		}
	}
	cout << dp[input.size() - 1];
	
	return 0;
}