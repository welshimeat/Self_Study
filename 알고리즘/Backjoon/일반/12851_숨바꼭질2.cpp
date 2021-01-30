#include <iostream>
#include <queue>
using namespace std;

void bfs();
queue<pair<int, int>> q;
int N, K, visited[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	bfs();

	return 0;
}

void bfs() {
	int position, time = 0, cnt = 0, fastest = 0;
	bool found = false;

	q.push({ N, time });
	visited[N] = -1;
	while (!q.empty()) {
		position = q.front().first;
		time = q.front().second;
		q.pop();
		if (!found) {
			if (position == K) {
				found = true;
				fastest = time;
				cnt++;
				continue;
			}
		}
		else {
			if (time == fastest) {
				if (position == K) {
					cnt++;
				}
				continue;
			}
			else break;
		}
		
		if (position > 0 && (visited[position - 1] == 0 || time + 1 <= visited[position - 1])) {
			visited[position - 1] = time + 1;
			q.push({ position - 1, time + 1 });
		}
		if (position < 100000 && (visited[position + 1] == 0 || time + 1 <= visited[position + 1])) {
			visited[position + 1] = time + 1;
			q.push({ position + 1, time + 1 });
		}
		if (position * 2 <= 100000 && (visited[position * 2] == 0 || time + 1 <= visited[position * 2])) {
			visited[position * 2] = time + 1;
			q.push({ position * 2, time + 1 });
		}
	}

	cout << fastest << '\n' << cnt;
}