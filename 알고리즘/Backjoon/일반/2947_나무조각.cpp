#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int piece[5], temp, index = 0;
	bool sorted;

	for (int i = 0; i < 5; i++) {
		cin >> piece[i];
	}
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (piece[i] > piece[i + 1]) {
				temp = piece[i + 1];
				piece[i + 1] = piece[i];
				piece[i] = temp;
				for (int j = 0; j < 5; j++) {
					cout << piece[j] << ' ';
				}
				cout << '\n';
			}
		}
		sorted = true;
		for (int i = 0; i < 4; i++) {
			if (piece[i] != i + 1) {
				sorted = false;
				break;
			}
		}
		if (sorted) break;
	}

	return 0;
}