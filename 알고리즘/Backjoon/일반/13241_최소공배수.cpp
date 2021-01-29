#include <iostream>
using namespace std;

long long int gcd(long long int, long long int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b, lcm;

	cin >> a >> b;
	if (a > b) {
		lcm = a * b / gcd(a, b);
	}
	else {
		lcm = a * b / gcd(b, a);
	}
	cout << lcm;

	return 0;
}

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		long long int r = a % b;
		a = b;
		b = r;
	}
	return a;
}