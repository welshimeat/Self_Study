#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, max = 0;
	string book;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> book;
		m[book]++;
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > max) {
			max = iter->second;
			book = iter->first;
		}
	}
	cout << book;
	return 0;
}