#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

list<int> ls;
vector<int> c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, num, index, time = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		c.push_back(num);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> num;
		ls.push_back(num);
	}
	sort(c.begin(), c.end(), greater<int>());
	ls.sort(greater<int>());
	auto iter = ls.begin();
	if (*iter > c[0]) {
		cout << -1;
		return 0;
	}
	
	while (ls.size()) {
		iter = ls.begin();
		index = 0;
		while (index != N) {
			if (*iter <= c[index]) {
				ls.erase(iter);
				if (!ls.size()) break;
				iter = ls.begin();
				index++;
			}
			else {
				iter++;
				if (iter == ls.end()) {
					break;
				}
			}
		}
		time++;
	}
	cout << time << '\n';
	

	return 0;
}