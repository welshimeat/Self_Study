#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int medal[1001][3], N, K, index, rank = 1;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> index;
		cin >> medal[index][0] >> medal[index][1] >> medal[index][2];
	}

	for (int i = 1; i <= N; i++) {
		if (medal[i][0] > medal[K][0]) {
			rank++;
		}
		else if (medal[i][0] == medal[K][0]) {
			if (medal[i][1] > medal[K][1]) {
				rank++;
			}
			else if (medal[i][1] == medal[K][1]) {
				if (medal[i][2] > medal[K][2]) {
					rank++;
				}
			}
		}
	}
	cout << rank;


	return 0;
}