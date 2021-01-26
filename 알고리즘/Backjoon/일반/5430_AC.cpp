#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n;
	string p;
	char array[400001];
	bool flag, reverse = false;
	deque<int> num_array;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> p >> n >> array;
		reverse = false;
		flag = true;
		char* ptr = strtok(array+1, ",]");
		while (ptr != NULL) {
			num_array.push_back(atoi(ptr));
			ptr = strtok(NULL, ",]");
		}
		for (int j = 0; j < p.size(); j++) {
			if (p[j] == 'R') {
				reverse = !reverse;
			}
			else {
				if (num_array.size() == 0) {
					flag = false;
					cout << "error" << endl;
					break;
				}
				if (reverse) {
					num_array.pop_back();
				}
				else {
					num_array.pop_front();
				}
				
			}
		}
		if (flag) {
			int size = num_array.size();
			cout << "[";
			if (!reverse) {
				for (int j = 0; j < size - 1; j++) {
					cout << num_array[j] << ',';
				}
				if (size >= 1) {
					cout << num_array[size - 1];
				}
			}
			else {
				for (int j = size - 1; j > 0; j--) {
					cout << num_array[j] << ',';
				}
				if (size >= 1) {
					cout << num_array[0];
				}
			}
			cout << "]" << endl;
		}
		memset(array, NULL, sizeof(array));
		num_array.clear();
	}

	return 0;
}