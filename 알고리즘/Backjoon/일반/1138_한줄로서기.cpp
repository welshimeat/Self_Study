#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, line[11] = { 0 }, input[11] = { 0 };

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> input[i];
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (line[j] == 0 || line[j] > i) {
				if (input[i] == cnt) {
					line[j] = i;
					break;
				}
				else {
					cnt++;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << line[i] << ' ';
	}

	return 0;
}