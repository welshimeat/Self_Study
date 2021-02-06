#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int T, from, to, visited[10000];
void bfs();
bool checkSosu(int n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> from >> to;
		bfs();
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}

void bfs() {
	int num, now;
	bool found = false;
	queue<pair<int, int>> q;

	q.push({ from, 0 });
	visited[from] = -1;
	while (!q.empty()) {
		num = q.front().first;
		now = q.front().second;
		q.pop();
		if (num == to) {
			found = true;
			break;
		}
		string num_str = to_string(num);
		for (int i = 0; i < 4; i++) {
			string new_str = num_str;
			for (char j = '0'; j <= '9'; j++) {				
				new_str[i] = j;
				int new_num = stoi(new_str);
				if (new_num > 1000 && (!visited[new_num] || visited[new_num] > now + 1) && checkSosu(new_num)) {
					q.push({ new_num, now + 1 });
					visited[new_num] = now + 1;
				}
			}
		}
	}
	if (found) {
		cout << now << '\n';
	}
	else {
		cout << "Impossible" << '\n';
	}
}

bool checkSosu(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}