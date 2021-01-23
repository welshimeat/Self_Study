#include <iostream>
#include <utility>
#include <list>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	list<pair<int, int>> lt;
	queue<int> truck;
	int n, w, L, a, total = 0, second = 1;

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) {
		cin >> a;
		truck.push(a);
	}
	while (1) {
		for (auto iter = lt.begin(); iter != lt.end(); iter++) {
			iter->second--;
		}
		if (!lt.empty() && lt.front().second == 0) {
			total -= lt.front().first;
			lt.pop_front();
		}
		
		if (!truck.empty() && total + truck.front() <= L) {
			lt.push_back(make_pair(truck.front(), w));
			total += truck.front();
			truck.pop();
		}
		else if (truck.empty() && lt.empty()) {
			break;
		}
		second++;
	}
	cout << second;
	
	return 0;
}