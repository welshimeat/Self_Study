#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<long long int, long long int>> v;
long long int X, A, sum, temp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> X >> A;
		v.push_back({ X, A });
		sum += A;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		temp += v[i].second;
		if (temp * 2 > sum) {
			cout << v[i].first;
			break;
		}
	}
	return 0;
}