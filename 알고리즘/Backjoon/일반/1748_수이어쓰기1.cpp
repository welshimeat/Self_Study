#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int n, now;
	long long ans = 0, length;
	scanf("%d", &n);

	length = to_string(n).length();
	now = pow(10, length - 1) - 1;
	ans += (n - now) * length;
	
	while (now != 0) {
		length = to_string(now).length();
		ans += (now - now / 10)* length;
		now /= 10;
	}

	printf("%lld", ans);
	return 0;
}