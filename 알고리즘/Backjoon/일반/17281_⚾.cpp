#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, player[10][51], index, score, max = 0, out, now;
	vector<int> v{ 2,3,4,5,6,7,8,9 };

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> player[j][i];
		}
	}
	do {
		index = -1;
		score = 0;
		vector<int> order(v);
		order.insert(order.begin() + 3, 1);
		for (int i = 1; i <= N; i++) {
			int position[10] = { 0 };
			out = 0;
			while (out != 3) {
				index = (index + 1) % 9;
				now = order[index];
				if (player[now][i] == 0) {
					out++;
					continue;
				}
				else if (player[now][i] == 1) {
					for (int j = 1; j <= 9; j++) {
						if (position[j] != 0) {
							position[j]++;
						}
					}
					position[now]++;
				}
				else if (player[now][i] == 2) {
					for (int j = 1; j <= 9; j++) {
						if (position[j] != 0) {
							position[j] += 2;
						}
					}
					position[now] += 2;
				}
				else if (player[now][i] == 3) {
					for (int j = 1; j <= 9; j++) {
						if (position[j] != 0) {
							position[j] += 3;
						}
					}
					position[now] += 3;
				}
				else {
					for (int j = 1; j <= 9; j++) {
						if (position[j] != 0) {
							position[j] += 4;
						}
					}
					position[now] += 4;
				}
				for (int j = 1; j <= 9; j++) {
					if (position[j] >= 4) {
						position[j] = 0;
						score++;
					}
				}
			}
		}
		if (score > max) {
			max = score;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << max;

	return 0;
}