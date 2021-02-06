#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n, cnt;
	multimap<string, string> m;
	string value, key;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ans = 1;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> value >> key;
			m.insert({ key, value });
		}
		for (auto iter = m.begin(); iter != m.end();) {
			cnt = m.count(iter->first);
			ans *= cnt + 1;
			while (cnt--) iter++;
		}
		m.clear();
		cout << ans - 1 << '\n';
	}
	return 0;
}