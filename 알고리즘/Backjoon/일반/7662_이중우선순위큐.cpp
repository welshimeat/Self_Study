#include <iostream>
#include <set>
using namespace std;

int T, k, n;
char oper;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		multiset<int> ms;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> oper >> n;
			if (oper == 'I') {
				ms.insert(n);
			}
			else {
				if (!ms.empty()) {
					if (n == 1){
						ms.erase(--ms.end());
					}
					else {
						ms.erase(ms.begin());
					}
				}
			}
		}
		if (ms.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
		}
	}

	return 0;
}