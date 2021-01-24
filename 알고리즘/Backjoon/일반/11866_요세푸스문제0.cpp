#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	list<int> lt, answer;
	list<int>::iterator iter;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		lt.push_back(i + 1);
	}
	iter = lt.begin();
	while (lt.size() != 0) {
		for (int i = 0; i < K-1; i++) {
			iter++;
			if (iter == lt.end()) {
				iter = lt.begin();
			}
		}
		answer.push_back(*iter);
		iter = lt.erase(iter);
		if (iter == lt.end()) {
			iter = lt.begin();
		}
	}
	cout << '<';
	iter = answer.begin();
	for (int i = 0; i < N; i++) {
		cout << *(iter++);
		if (i != N - 1)
			cout << ", ";
	}
	cout << '>';
	return 0;
}