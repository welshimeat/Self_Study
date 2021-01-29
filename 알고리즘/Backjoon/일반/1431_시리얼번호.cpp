#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string, string);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string serial[1000];
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> serial[i];
	}

	sort(serial, serial + N, compare);
	for (int i = 0; i < N; i++) {
		cout << serial[i] << '\n';
	}

	return 0;
}

bool compare(string a, string b) {
	int a_len = a.length(), b_len = b.length(),
		a_sum = 0, b_sum = 0;
	if (a_len != b_len) return a_len < b_len;
	else {
		for (int i = 0; i < a_len; i++) {
			if (a[i] >= '1' && a[i] <= '9') {
				a_sum += a[i] - '0';
			}
			if (b[i] >= '1' && b[i] <= '9') {
				b_sum += b[i] - '0';
			}
		}
		if (a_sum != b_sum) return a_sum < b_sum;
		else {
			return a < b;
		}
	}
}

