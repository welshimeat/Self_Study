#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, block[1000], sum = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> block[i];
	}

	sort(block, block + N);
	for(int i=0; i<N; i++){
		if (sum + 1 >= block[i]) sum += block[i];
		else {
			break;
		}
	}
	cout << sum + 1 << endl;


	return 0;
}