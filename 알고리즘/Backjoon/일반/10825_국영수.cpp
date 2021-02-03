#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, korean, english, math;
string name;
vector<tuple<string, int, int, int>> v;
bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> korean >> english >> math;
		v.push_back({ name, korean, english, math });
	}
	sort(v.begin(), v.end(), compare);
	for (auto i : v) {
		cout << get<0>(i) << '\n';
	}


	return 0;
}

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
	if (get<1>(a) != get<1>(b)) {
		return get<1>(a) > get<1>(b);
	}
	else {
		if (get<2>(a) != get<2>(b)) {
			return get<2>(a) < get<2>(b);
		}
		else {
			if (get<3>(a) != get<3>(b)) {
				return get<3>(a) > get<3>(b);
			}
			else {
				return get<0>(a) < get<0>(b);
			}
		}
	}
}