#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int N, M, a, b, dist[1001];
vector<pair<int, int>> vertex[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void Dijkstra();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v, w;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		vertex[u].push_back({ v, w });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
	cin >> a >> b;

	Dijkstra();
	cout << dist[b];

	return 0;
}

void Dijkstra() {
	pq.push({ 0, a });
	dist[a] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (dist[node] < cost) continue;
		for (int i = 0; i < vertex[node].size(); i++) {
			int new_cost = cost + vertex[node][i].second;
			int new_node = vertex[node][i].first;
			if (dist[new_node] > new_cost) {
				dist[new_node] = new_cost;
				pq.push({ new_cost, new_node });
			}
		}
	}
}