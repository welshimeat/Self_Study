#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, kim, lim, round = 0;

	cin >> N >> kim >> lim;

	while (kim != lim) {
		if (kim % 2 == 1) {
			kim = kim / 2 + 1;
		}
		else {
			kim /= 2;
		}
		if (lim % 2 == 1) {
			lim = lim / 2 + 1;
		}
		else {
			lim /= 2;
		}		
		round++;
	}
	cout << round;


	return 0;
}