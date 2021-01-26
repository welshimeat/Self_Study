#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		int A, B;
		A = abs(a);
		B = abs(b);
		if (A == B) {
			return a > b;
		}
		else {
			return A > B;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, compare> pq;
	int N, x;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}

		}
	}


	return 0;
}
