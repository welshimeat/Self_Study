#include <iostream>
#include <list>
#include <vector>
using namespace std;

list<pair<int, int>> l;
vector<int> answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, cnt;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		l.push_back({ i + 1, num });
	}
	auto iter = l.begin();
	while (1) {
		answer.push_back(iter->first);
		cnt = iter->second;
		iter = l.erase(iter);
		if (iter == l.end()) iter = l.begin();
		if (l.empty()) break;
		if (cnt > 0) {
			for (int i = 1; i < cnt; i++) {
				if (iter == l.end()) {
					iter = l.begin();
				}
				else {
					iter++;
					if (iter == l.end()) iter = l.begin();
				}
			}
		}
		else {
			for (int i = 0; i < -cnt; i++) {
				if (iter == l.begin()) {
					iter = l.end();
				}
				iter--;
			}
		}
	}

	for (int i : answer) {
		cout << i << ' ';
	}

	return 0;
}