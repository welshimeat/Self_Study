#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string signal, result;
	char** msg;

	cin >> N;
	msg = new char*[5];
	for (int i = 0; i < 5; i++) {
		msg[i] = new char[N / 5];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < N / 5; j++) {
			cin >> msg[i][j];
		}
	}

	for (int i = 0; i < N / 5; i++) {
		if (msg[0][i] == '.') {
			continue;
		}
		else if (i + 1 < N / 5) {
			if (msg[0][i + 1] == '.' && msg[1][i + 1] == '.' && msg[2][i + 1] == '.' && msg[3][i + 1] == '.' && msg[4][i + 1] == '.') {
				result += "1";
				i -= 2;
			}
			else if (msg[1][i] == '#' && msg[1][i + 1] == '.' && msg[2][i + 1] == '.' && msg[3][i + 1] == '.') {
				result += "0";
			}
			else if (msg[3][i + 2] == '.') {
				result += "2";
			}
			else if (msg[1][i] == '.' && msg[2][i] == '#') {
				result += "3";
			}
			else if (msg[0][i+1] == '.') {
				result += "4";
			}
			else if (msg[3][i] == '.' && msg[1][i+2] == '.') {
				result += "5";
			}
			else if (msg[3][i] == '#' && msg[1][i + 2] == '.') {
				result += "6";
			}
			else if (msg[1][i] == '.') {
				result += "7";
			}
			else if (msg[3][i] == '#') {
				result += "8";
			}
			else {
				result += "9";
			}
			i += 3;
		}
		else {
			result += "1";
		}
	}
	cout << result;

	return 0;
}