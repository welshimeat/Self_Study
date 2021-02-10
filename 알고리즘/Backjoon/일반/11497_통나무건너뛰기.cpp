#include <iostream>
#include <list>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, input;
	list<int> tree;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> input;
			tree.push_back(input);
		}

		tree.sort(greater<int>());
		auto iter = ++tree.begin();
		while (1) {
			tree.push_front(*iter);
			tree.erase(iter++);
			if (iter != tree.end()) {
				iter++;
				if (iter == tree.end()) {
					break;
				}
			}
			else {
				break;
			}
		}
		int max = abs(tree.back() - tree.front());
		int previous = tree.front();
		for (auto iter = ++tree.begin(); iter != tree.end(); iter++) {
			if (abs(*iter - previous) > max) {
				max = abs(*iter - previous);
			}
			previous = *iter;
		}
		cout << max << '\n';
		tree.clear();
	}

	return 0;
}