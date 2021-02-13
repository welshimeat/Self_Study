#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
vector<char> answer;
int n, last = 0, num;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num > last) {
			for (int j = 1; j <= num - last; j++) {
				s.push(last + j);
				answer.push_back('+');
			}
			last = num;
			s.pop();
			answer.push_back('-');
		}
		else if (num < last) {
			if (!s.empty() && s.top() == num) {
				s.pop();
				answer.push_back('-');
			}
			else {
				cout << "NO" << '\n';
				return 0;
			}
		}
		else {
			cout << "NO" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}
	return 0;
}