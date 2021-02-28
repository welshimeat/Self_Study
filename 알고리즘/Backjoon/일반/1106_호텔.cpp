#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;
int person[1100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int C, N, a, b;

	for (int i = 1; i < 1100; i++) {
		person[i] = INF;
	}
	cin >> C >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		for (int j = 0; j < 1100; j++) {
			if (person[j] == INF) continue;
			for (int k = 1; j + b * k < 1100; k++) {
				person[j + b * k] = min(person[j + b * k], person[j] + a * k);
			}
		}
	}
	sort(person + C, person + 1100);
	cout << person[C];

	return 0;
}