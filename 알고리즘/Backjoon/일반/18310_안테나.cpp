#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int N, home[200000], pivot;
double avg;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}
	sort(home, home + N);
	cout << home[(N - 1) / 2];

	return 0;
}