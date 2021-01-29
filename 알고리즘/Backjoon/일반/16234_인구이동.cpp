#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

void bfs(int, int);
int N, L, R, map[50][50], visited[50][50], group, cnt;
queue<pair<int, int>> q;
vector<pair<int, int>> v[1250];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	while (1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bfs(i, j);
				}
			}
		}
		memset(visited, 0, sizeof(visited));
		if (group == 0) {
			break;
		}
		else {
			for (int i = 0; i < group; i++) {
				int sum = 0;
				for (int j = 0; j < v[i].size(); j++) {
					sum += map[v[i][j].first][v[i][j].second];
				}
				sum /= v[i].size();
				for (int j = 0; j < v[i].size(); j++) {
					map[v[i][j].first][v[i][j].second] = sum;
				}
				v[i].clear();
			}
			cnt++;
			group = 0;
		}
	}
	cout << cnt << '\n';
	return 0;
}

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = 1;
	v[group].push_back({ x, y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		if (x + 1 != N && !visited[x+1][y] && abs(map[x][y] - map[x+1][y]) >= L && abs(map[x][y] - map[x + 1][y]) <= R) {
			q.push({ x + 1, y });
			visited[x + 1][y] = 1;
			v[group].push_back({ x + 1, y });
		}
		if (x != 0 && !visited[x - 1][y] && abs(map[x][y] - map[x - 1][y]) >= L && abs(map[x][y] - map[x - 1][y]) <= R) {
			q.push({ x - 1, y });
			visited[x - 1][y] = 1;
			v[group].push_back({ x - 1, y });
		}
		if (y + 1 != N && !visited[x][y + 1] && abs(map[x][y] - map[x][y + 1]) >= L && abs(map[x][y] - map[x][y + 1]) <= R) {
			q.push({ x, y + 1 });
			visited[x][y + 1] = 1;
			v[group].push_back({ x, y + 1 });
		}
		if (y != 0 && !visited[x][y - 1] && abs(map[x][y] - map[x][y - 1]) >= L && abs(map[x][y] - map[x][y - 1]) <= R) {
			q.push({ x, y - 1 });
			visited[x][y - 1] = 1;
			v[group].push_back({ x, y - 1 });
		}
	}
	if (v[group].size() == 1) {
		v[group].pop_back();
	}
	else {
		group++;
	}
}