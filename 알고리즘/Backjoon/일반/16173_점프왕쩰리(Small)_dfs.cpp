#include <iostream>
using namespace std;
int N, map[3][3];
void dfs(int, int);
bool flag = false;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x = 0, y = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dfs(x, y);
	if (flag) {
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}

	return 0;
}

void dfs(int x, int y) {
	if (map[x][y] == 0) {
		return;
	}
	else if (x == N - 1 && y == N - 1) {
		flag = true;
		return;
	}

	if (x + map[x][y] < N) {
		dfs(x + map[x][y], y);
	}
	if (y + map[x][y] < N) {
		dfs(x, y + map[x][y]);
	}
}