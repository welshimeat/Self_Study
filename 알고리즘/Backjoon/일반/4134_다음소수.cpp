#include <iostream>
#include <vector>
using namespace std;

bool num[63301];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int n;
	bool found;
	int T;

	for (int i = 2; i <= 63300; i++) {
		for (int j = 2; i * j <= 63300; j++) {
			num[i * j] = true;
		}
	}
	for (int i = 2; i <= 63300; i++) {
		if (!num[i]) v.push_back(i);
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		if (n <= 1) {
			cout << 2 << '\n';
			continue;
		}
		while (1) {
			found = true;
			for (int j = 0; j < v.size(); j++) {
				if (n <= v[j]) {
					break;
				}
				else if (n % v[j] == 0) {
					found = false;
					break;
				}
			}
			if (found) {
				cout << n << '\n';
				break;
			}
			n++;
		}
	}
	return 0;
}