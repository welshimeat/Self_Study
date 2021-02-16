#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string input, answer = "";

	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		switch (input[i]) {
		case '*' :
		case '/': while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
			answer.push_back(s.top());
			s.pop();
		} s.push(input[i]); break;
		case '+' :
		case '-' : while (!s.empty() && (s.top() != '(')) {
			answer.push_back(s.top());
			s.pop();
		} s.push(input[i]); break;
		case '(' : s.push(input[i]); break;
		case ')' : while (!s.empty() && (s.top() != '(')) {
			answer.push_back(s.top());
			s.pop();
		} s.pop();  break;
		default: answer.push_back(input[i]);
		}
	}

	while (!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}

	cout << answer << '\n';

	return 0;
}