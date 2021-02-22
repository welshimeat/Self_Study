#include <iostream>
#include <string>
using namespace std;

int N, B, R;
string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> input;
	if (input[0] == 'B') B++;
	else R++;
	for (int i = 1; i < N; i++) {
		if (input[i] == 'B' && input[i - 1] == 'R') B++;
		else if (input[i] == 'R' && input[i - 1] == 'B') R++;
	}
	if (R >= B) cout << B + 1;
	else cout << R + 1;

	return 0;
}