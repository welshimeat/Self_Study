#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, cnt = 0;
	string input, str;

	cin >> input >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		str += str;
		if (((int)str.find(input)) != -1) {
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}