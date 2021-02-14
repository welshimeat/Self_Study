#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unordered_set<string> us;
	int N, M, cnt = 0;
	string str;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		us.insert(str);
	}
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (us.find(str) != us.end()) cnt++;
	}
	cout << cnt;

	return 0;
}