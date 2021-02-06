#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	vector<int> sorted, input;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		sorted.push_back(num);
		input.push_back(num);
	}

	sort(sorted.begin(), sorted.end());
	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
	for (int i = 0; i < N; i++) {
		int index = lower_bound(sorted.begin(), sorted.end(), input[i]) - sorted.begin();
		cout << index << ' ';
	}
	return 0;
}