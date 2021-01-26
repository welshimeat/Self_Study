#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	int cnt, max = 50;

	cin >> A >> B;
	for (int i = 0; i <= B.length() - A.length(); i++) {
		cnt = 0;
		for(int j = 0; j < A.length(); j++){
			if (A[j] != B[i + j]) {
				cnt++;
			}
		}
		if (max > cnt) {
			max = cnt;
		}
	}
	cout << max;


	return 0;
}