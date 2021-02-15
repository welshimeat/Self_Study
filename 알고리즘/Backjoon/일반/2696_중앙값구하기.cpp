#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, M, num;
	
	cin >> T;
	for (int i = 0; i < T; i++) {
		priority_queue<int> maxPQ;
		priority_queue<int, vector<int>, greater<int>> minPQ;
		vector<int> answer;
		cin >> M >> num;
		maxPQ.push(num);
		answer.push_back(num);
		for (int j = 2; j <= M; j++) {
			cin >> num;
			if (maxPQ.top() >= num) {
				maxPQ.push(num);
			}
			else {
				minPQ.push(num);
			}

			if (minPQ.size() > maxPQ.size()) {
				maxPQ.push(minPQ.top());
				minPQ.pop();
			}
			else if (maxPQ.size() > minPQ.size() + 1) {
				minPQ.push(maxPQ.top());
				maxPQ.pop();
			}
			if(j % 2 == 1) answer.push_back(maxPQ.top());
		}
		cout << answer.size() << '\n';
		for (int j = 1; j <= answer.size(); j++) {
			cout << answer[j-1] << ' ';
			if (j % 10 == 0) cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}