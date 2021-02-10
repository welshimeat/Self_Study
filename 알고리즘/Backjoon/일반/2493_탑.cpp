#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, top[500001];
stack<pair<int, int>> s;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> top[i];
	}

	s.push({ top[1], 1 });
	answer.push_back(0);
	for (int i = 2; i <= N; i++) {
		if (top[i] < s.top().first){
			answer.push_back(s.top().second);
		}
		else {
			while (!s.empty() && top[i] >= s.top().first) {
				s.pop();
			}
			if (s.empty()) {
				answer.push_back(0);
			}
			else {
				answer.push_back(s.top().second);
			}
		}
		s.push({ top[i], i });
	}

	for (int i : answer) {
		cout << i << ' ';
	}
	return 0;
}