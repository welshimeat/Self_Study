#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;
string input;
int total = 0, value = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '(') {
			value *= 2;
			s.push(input[i]);
		}
		else if(input[i] == '['){
			value *= 3;
			s.push(input[i]);
		}
		else {
			if (s.empty() || (s.top() == '(' && input[i] == ']') || (s.top() == '[' && input[i] == ')')) {
				cout << 0;
				return 0;
			}
			else {
				if (input[i] == ')') {
					if (input[i-1] == '(') {
						total += value;
					}
					s.pop();
					value /= 2;
				}
				else {
					if (input[i - 1] == '[') {
						total += value;
					}
					s.pop();
					value /= 3;
				}
			}
		}
	}
	if (!s.empty()) {
		cout << 0;
		return 0;
	}

	cout << total;

	return 0;
}