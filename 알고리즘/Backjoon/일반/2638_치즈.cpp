#include <iostream>
#include <queue>
#include <list>
using namespace std;

int N, M, map[100][100], visited[100][100], direction_x[4] = { 1, -1, 0, 0 }, direction_y[4] = { 0, 0, 1, -1 }, time = 0;
queue<pair<int, int>> q, mq;
list<pair<int, int>> lt;
void separateAir(int x, int y);
void meltdown();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				lt.push_back({ i, j });
			}
		}
	}
	separateAir(0, 0);
	while (!lt.empty()) {
		meltdown();
		time++;
	}
	cout << time;

	return 0;
}

void separateAir(int x, int y){
	q.push({ x, y });
	map[x][y] = -1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && map[new_x][new_y] == 0) {
				q.push({ new_x , new_y });
				map[new_x][new_y] = -1;
			}
		}
	}
}

void meltdown() {
	int cnt;

	for (auto iter = lt.begin(); iter != lt.end();) {
		int x = (*iter).first;
		int y = (*iter).second;
		cnt = 0;
		for (int i = 0; i < 4; i++) {
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < M && map[new_x][new_y] == -1) {
				cnt++;
			}
			if (cnt == 2) {
				map[x][y] = 0;
				mq.push({ x, y });
				lt.erase(iter++);
				break;
			}
		}
		if (cnt != 2) {
			iter++;
		}
	}

	while (!mq.empty()) {
		separateAir(mq.front().first, mq.front().second);
		mq.pop();
	}
}