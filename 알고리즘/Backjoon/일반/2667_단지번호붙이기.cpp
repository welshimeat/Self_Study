#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, label[625], num;
char map[25][25];
bool visited[25][25];
int dir_x[4] = { 1, -1, 0, 0 }, dir_y[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;

void bfs(int x, int y);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1' && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}
	sort(label, label + num);
	cout << num << '\n';
	for (int i = 0; i < num; i++) {
		cout << label[i] << '\n';
	}
	

	return 0;
}

void bfs(int x, int y) {
	int cnt = 1;
	q.push({ x, y });
	visited[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + dir_x[i];
			int new_y = y + dir_y[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N && map[new_x][new_y] == '1' && !visited[new_x][new_y]) {
				visited[new_x][new_y] = true;
				q.push({ new_x, new_y });
				cnt++;
			}
		}
	}
	label[num++] = cnt;
}