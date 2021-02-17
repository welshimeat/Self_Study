#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<double> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, alph[26];
	double a, b, temp = 0;
	string input;

	cin >> N >> input;
	for (int i = 0; i < N; i++) {
		cin >> alph[i];
	}
	for (int i = 0; i < input.size(); i++) {
		switch (input[i]) {
		case '+': a = s.top(); s.pop(); b = s.top(); s.pop(); temp = a + b; s.push(temp);  break;
		case '-': a = s.top(); s.pop(); b = s.top(); s.pop(); temp = b - a; s.push(temp);  break;
		case '*': a = s.top(); s.pop(); b = s.top(); s.pop(); temp = a * b; s.push(temp);  break;
		case '/': a = s.top(); s.pop(); b = s.top(); s.pop(); temp = b / a; s.push(temp);  break;
		default: s.push(alph[input[i] - 'A']);
		}
	}
	cout.precision(2);
	cout << fixed;
	cout << s.top();

	return 0;
}