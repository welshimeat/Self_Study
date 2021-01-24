#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, w, max = 0, total;
	vector<int> v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> w;
		v.push_back(w);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		total = (N - i) * v[i];
		if (total > max) {
			max = total;
		}
	}
	cout << max;

	return 0;
}