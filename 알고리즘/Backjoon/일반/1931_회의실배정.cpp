#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, s, e, now = 0, cnt = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back({ e, s });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		s = v[i].second;
		e = v[i].first;
		if (s >= now) {
			now = e;
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}