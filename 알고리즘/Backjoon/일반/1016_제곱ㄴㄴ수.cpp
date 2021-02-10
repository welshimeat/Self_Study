#include <iostream>

long long int min, max, cnt = 0, value;
bool visited[1000001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> min >> max;
	for (long long int i = 2; i*i <= max; i++) {
		long long int square = i * i;
		if (min % square == 0) value = 0;
		else value = square - (min % square);
		
		while (value <= max - min) {
			visited[value] = true;
			value += square;
		}
	}

	for (int i = 0; i < max - min + 1; i++) {
		if (!visited[i]) cnt++;
	}
	std::cout << cnt;
	return 0;
}
