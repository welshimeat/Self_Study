#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, box[1000], inside[1000], max = 1;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
		inside[i] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j] && inside[i] < inside[j] + 1) {
				inside[i] = inside[j] + 1;
				if (max < inside[i]) {
					max = inside[i];
				}
			}
		}
	}
	cout << max;



	return 0;
}