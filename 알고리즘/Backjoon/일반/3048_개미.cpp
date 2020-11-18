#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N1, N2, T, length, index;
	string S1, S2, now;
	char temp;
	bool flag;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N1 >> N2 >> S1 >> S2 >> T;

	length = N1 + N2;
	reverse(S1.begin(), S1.end());
	now = S1 + S2;
	
	for(int i = 0; i < T; i++){
		flag = true;
		for (int j = 1; j <= N1; j++) {
			if (!flag) {
				break;
			}
			index = now.find(S1[N1 - j]);
			if (index == length - j) {
				continue;
			}
			if (index > 0 && (S1.find(now[index - 1])) != -1) {
				flag = false;
			}
			if (index + 1 < length && S2.find(now[index+1]) != -1) {
				temp = now[index];
				now[index] = now[index+1];
				now[index+1] = temp;
			}
		}
	}
	cout << now;
	return 0;
}