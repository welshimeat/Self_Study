#include <iostream>
#include <queue>
#include <vector>

#define INF 9999999
using namespace std;

int V, E, K, dist[20001];
vector<pair<int, int>> vertex[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void Dijkstra();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int u, v, w;
	
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		vertex[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	Dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
}

void Dijkstra() {
	pq.push({ 0, K });
	dist[K] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < vertex[node].size(); i++) {
			int new_cost = vertex[node][i].second;
			int new_node = vertex[node][i].first;
			if (dist[new_node] > cost + new_cost) {
				dist[new_node] = cost + new_cost;
				pq.push({ dist[new_node], new_node });
			}
		}
	}
}