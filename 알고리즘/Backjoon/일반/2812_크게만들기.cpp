#include <iostream>
#include <string>
using namespace std;

int N, K, cnt;
string temp, num, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> num;
	for (int i = 0; i < num.length(); i++) {
		while (K && !ans.empty() && ans.back() < num[i]) {
			ans.pop_back();
			K--;
		}
		ans.push_back(num[i]);
	}
	for (int i = 0; i < ans.length() - K; i++) {
		cout << ans[i];
	}

	return 0;
}
