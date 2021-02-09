#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, input, pivot, dist, sum = 0;
	vector<int> v;

	cin >> N >> pivot;
	for (int i = 0; i < N-1; i++) {
		cin >> input;
		v.push_back(input - pivot);
		pivot = input;
	}

	dist = gcd(v[0], v[1]);
	for (int i = 2; i < v.size(); i++) {
		dist = gcd(dist, v[i]);
	}
	for (int i = 0; i < v.size(); i++) {
		sum += v[i] / dist - 1;
	}
	cout << sum;

	return 0;
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}