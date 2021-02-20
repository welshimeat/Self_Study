#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, pivot, student, answer = 0;

	cin >> N >> K >> pivot;
	for (int i = 1; i < N; i++) {
		cin >> student;
		v.push_back(student - pivot);
		pivot = student;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N - K; i++) {
		answer += v[i];
	}
	cout << answer;
	return 0;
}