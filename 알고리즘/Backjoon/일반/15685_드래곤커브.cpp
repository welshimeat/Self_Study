#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, x, y, d, g, map[101][101] = { 0 }, cnt = 0, size,
		move[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		map[y][x] = 1;
		vector<int> direction;
		direction.push_back(d);
		x += move[d][0];
		y += move[d][1];
		map[y][x] = 1;
		for (int i = 1; i <= g; i++) {
			size = direction.size();
			for (int j = size - 1; j >= 0; j--) {
				d = (direction[j] + 1) % 4;
				x += move[d][0];
				y += move[d][1];
				map[y][x] = 1;
				direction.push_back(d);
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				cnt++;
		}
	}

	cout << cnt;


	return 0;
}