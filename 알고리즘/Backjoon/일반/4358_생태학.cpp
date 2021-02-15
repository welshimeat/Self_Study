#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout.setf(ios::fixed);
	cout.precision(4);
	double cnt = 0;
	string name;

	while (getline(cin, name)) {
		m[name]++;
		cnt++;
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ' ' << iter->second / cnt * 100 << '\n';
	}

	return 0;
}