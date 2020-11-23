#pragma warning(disable:4996)
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	string input;
	unordered_set<string> s;
	set<string> answer;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		s.insert(input);
	}
	for (int i = 0; i < M; i++) {
		cin >> input;
		if (s.find(input) != s.end()) {
			answer.insert(input);
		}
	}
	cout << answer.size() << '\n';
	for (auto iter = answer.begin(); iter != answer.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}