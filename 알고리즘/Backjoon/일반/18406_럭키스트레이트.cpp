#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, left = 0, right = 0;

	cin >> N;
	string str = to_string(N);
	for (int i = 0; i < str.length() / 2; i++) {
		left += str[i];
	}
	for (int i = str.length()/2; i < str.length(); i++) {
		right += str[i];
	}

	if (left == right) {
		cout << "LUCKY";
	}
	else {
		cout << "READY";
	}

	return 0;
}