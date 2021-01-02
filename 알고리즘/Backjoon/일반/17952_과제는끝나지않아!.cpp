#include <iostream>
#include <utility>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, input, score, time, total = 0;
	list<pair<int, int>> lt;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == 1) {
			cin >> score >> time;
			lt.push_front(make_pair(score, time));
		}
		lt.front().second--;
		if (lt.front().second == 0) {
			total += lt.front().first;
			lt.pop_front();
		}
	}
	cout << total;

	return 0;
}

