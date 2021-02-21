#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long T, K, deck, sum;

	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long answer = 0;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> deck;
			pq.push(deck);
		}
		while (pq.size() != 1) {
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			pq.push(sum);
			answer += sum;
		}
		cout << answer << '\n';
	}
	return 0;
}