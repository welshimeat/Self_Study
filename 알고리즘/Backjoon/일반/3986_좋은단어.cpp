#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, cnt = 0;
	string input;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		stack<char> s;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			if (s.empty()) {
				s.push(input[j]);
			}
			else {
				if (s.top() == input[j]) s.pop();
				else s.push(input[j]);
			}
		}
		if (s.empty()) cnt++;
	}
	cout << cnt;
	return 0;
}