#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string a, string b);
string combination(int n, int m);
string cache[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	cin >> n >> m;
	cout << combination(n, m);
	
	return 0;
}

string add(string a, string b) {
	long long int sum = 0;
	string num;

	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		num.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(num.begin(), num.end());
	return num;
}

string combination(int n, int m) {
	if (n == m || m == 0) {
		return "1";
	}
	if (cache[n][m] == "") {
		cache[n][m] = add(combination(n - 1, m - 1), combination(n - 1, m));
	}
	return cache[n][m];
}