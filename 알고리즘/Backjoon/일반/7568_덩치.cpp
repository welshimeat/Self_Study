#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, person[50][2], cnt;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> person[i][0] >> person[i][1];
	}

	for (int i = 0; i < N; i++) {
		cnt = 1;
		for (int j = (i + 1) % N; j != i; j = (j + 1) % N) {
			if (person[i][0] < person[j][0] && person[i][1] < person[j][1]) {
				cnt++;
			}
		}
		cout << cnt << " ";
	}
	return 0;
}