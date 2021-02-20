#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<tuple<int, int, int>> v;
int village[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, C, M, a, b, w, max, total = 0;

	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		v.push_back({ b, a, w });
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= N; i++) {
		village[i] = C;
	}

	for (int i = 0; i < v.size(); i++) {
		a = get<1>(v[i]);
		b = get<0>(v[i]);
		w = get<2>(v[i]);
		max = w;
		for (int j = a; j < b; j++) {
			if (village[j] < max) {
				max = village[j];
			}
		}
		for (int j = a; j < b; j++) {
			village[j] -= max;
		}
		total += max;
	}
	cout << total;
	return 0;
}