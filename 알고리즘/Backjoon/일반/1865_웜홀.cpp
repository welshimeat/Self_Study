#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

int TC, N, M, W, dist[501];
vector<pair<int, pair<int, int>>> v;
void BellmanFord();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int S, E, T;

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		cin >> N >> M >> W;
		for (int j = 0; j < M; j++) {
			cin >> S >> E >> T;
			v.push_back({ S, { E, T } });
			v.push_back({ E, { S, T } });
		}
		for (int j = 0; j < W; j++) {
			cin >> S >> E >> T;
			v.push_back({ S, { E, -T } });
		}
		for (int j = 1; j <= N; j++) {
			dist[j] = INF;
		}
		BellmanFord();
		v.clear();
	}


	return 0;
}

void BellmanFord() {
	int cnt = 0;

	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		bool isActive = false;
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].first;
			int to = v[j].second.first;
			int cost = v[j].second.second;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				isActive = true;
			}
		}
		if (isActive) cnt++;
	}
	if (cnt == N)
		cout << "YES\n";
	else
		cout << "NO\n";
}