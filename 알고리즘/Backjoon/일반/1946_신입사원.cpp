#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, a, b, min, cnt;
	vector<pair<int, int>> v;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cnt = 1;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> a >> b;
			v.push_back({ a, b });
		}
		sort(v.begin(), v.end());
		min = v[0].second;
		for (int j = 1; j < N; j++) {
			if (v[j].second < min) {
				min = v[j].second;
				cnt++;
			}
		}
		cout << cnt << '\n';
		v.clear();
	}

	return 0;
}