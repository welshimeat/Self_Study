#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, direction[1001] = { 0 }, now, cycle;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cycle = 0;
		int visited[1001] = { 0 };
		for (int j = 1; j <= N; j++) {
			cin >> direction[j];
		}
		for (int j = 1; j <= N; j++) {
			if (!visited[j]) {
				visited[j] = 1;
				now = j;
				while (1) {
					now = direction[now];
					if (now == j) {
						cycle++;
						break;
					}
					visited[now] = 1;
				}
			}
		}
		cout << cycle << endl;
	}


	return 0;
}