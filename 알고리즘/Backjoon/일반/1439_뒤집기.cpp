#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string S;
	bool flag = true;
	int black = 0, white = 0;

	cin >> S;
	if (S.length() >= 1) {
		black++;
	}
	for (int i = 1; i < S.length(); i++) {
		if (S[i - 1] != S[i]) {
			if (flag) {
				white++;
			}
			else {
				black++;
			}
			flag = !flag;
		}
	}
	if (black > white) {
		cout << white;
	}
	else {
		cout << black;
	}

	return 0;
}