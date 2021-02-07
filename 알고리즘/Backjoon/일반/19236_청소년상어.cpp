#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

pair<int, int> **map, direction[9] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} };
stack<tuple<int, int, pair<int, int>**, int>> s;
void dfs();
void fishMove(int shark_x, int shark_y, pair<int, int>** temp);
pair<int, int>** copy(pair<int, int> **save);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map = new pair<int, int>* [4];
	for (int i = 0; i < 4; i++) {
		map[i] = new pair<int, int>[4];
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j].first >> map[i][j].second;
		}
	}
	dfs();

	return 0;
}

void dfs() {
	int max = 0;

	s.push({ 0, 0, copy(map), map[0][0].first });
	
	while (!s.empty()) {
		int x = get<0>(s.top());
		int y = get<1>(s.top());
		pair<int, int>** temp = get<2>(s.top());
		int point = get<3>(s.top());
		int dir = temp[x][y].second;
		s.pop();
		temp[x][y].first = -1;
		
		if (point > max) {
			max = point;
		}
		fishMove(x, y, temp);
		
		int i = 1;
		while (1) {
			int new_x = x + direction[dir].first * i;
			int new_y = y + direction[dir].second * i;
			if (new_x < 0 || new_x >= 4 || new_y < 0 || new_y >= 4) {
				break;
			}
			else if (temp[new_x][new_y].first != -1) {
				s.push({ new_x, new_y, copy(temp), point + temp[new_x][new_y].first });
			}
			i++;
		}

	}

	cout << max;
}

void fishMove(int shark_x, int shark_y, pair<int, int>** temp) {
	for (int fish = 1; fish <= 16; fish++) {
		bool found = false;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (temp[i][j].first == fish) {
					found = true;
					int dir = temp[i][j].second;
					for (int k = 0; k < 8; k++) {
						int new_dir = dir + k;
						if (new_dir > 8) new_dir %= 8;
						int new_x = i + direction[new_dir].first;
						int new_y = j + direction[new_dir].second;
						if (new_x >= 0 && new_x < 4 && new_y >= 0 && new_y < 4 && (new_x != shark_x || new_y != shark_y)) {
							temp[i][j].second = new_dir;
							swap(temp[i][j], temp[new_x][new_y]);
							break;
						}
					}
					if (found) break;
				}
			}
			if (found) break;
		}
	}
}

pair<int, int>** copy(pair<int, int>** save) {
	pair<int, int>** temp;
	temp = new pair<int, int>*[4];
	for (int i = 0; i < 4; i++) {
		temp[i] = new pair<int, int>[4];
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp[i][j] = save[i][j];
		}
	}
	return temp;
}