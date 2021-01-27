#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	string input;
	list<char> lt;
	list<char>::iterator iter;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		iter = lt.end();
		cin >> input;
		for (int j = 0; j < input.length(); j++) {
			if (input[j] == '<') {
				if (iter != lt.begin()) {
					iter--;
				}
			}
			else if (input[j] == '>') {
				if (iter != lt.end()) {
					iter++;
				}
			}
			else if (input[j] == '-') {
				if (iter != lt.begin()) {
					iter = lt.erase(--iter);
				}
			}
			else {
				lt.insert(iter, input[j]);
			}
		}
		for (iter = lt.begin(); iter != lt.end(); iter++) {
			cout << *iter;
		}
		cout << '\n';
		lt.clear();
	}
	return 0;
}