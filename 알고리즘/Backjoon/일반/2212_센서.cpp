#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, pivot, num, total;
vector<int> v, diff;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	if (K >= N) {
		cout << 0;
		return 0;
	}
	sort(v.begin(), v.end());
	pivot = v[0];
	for (int i = 1; i < N; i++) {
		diff.push_back(v[i] - pivot);
		pivot = v[i];
	}
	sort(diff.begin(), diff.end());
	for (int i = 0; i < K - 1; i++) {
		diff.pop_back();
	}
	for (int i = 0; i < diff.size(); i++) {
		total += diff[i];
	}
	cout << total;
	return 0;
}