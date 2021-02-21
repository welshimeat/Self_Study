#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, deck, sum, answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> deck;
		pq.push(deck);
	}
	

	while(pq.size() != 1){
		sum = pq.top();
		pq.pop();
		sum += pq.top();
		pq.pop();
		pq.push(sum);
		answer += sum;
	}
	cout << answer;
	return 0;
}