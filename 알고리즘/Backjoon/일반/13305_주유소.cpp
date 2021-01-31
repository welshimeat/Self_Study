#include <iostream>
using namespace std;

int N;
long long road[99999], oil[100000], cost = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int min = 1000000000;

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> oil[i];
	}

	for (int i = 0; i < N - 1; i++) {
		if (oil[i] < min) {
			min = oil[i];
		}
		cost += road[i] * min;
	}
	cout << cost;
	return 0;
}