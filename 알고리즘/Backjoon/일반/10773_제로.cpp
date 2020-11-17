#pragma warning(disable:4996)
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
	int K, num;
	vector<int> answer;

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);
		if (num == 0) {
			answer.pop_back();
		}
		else {
			answer.push_back(num);
		}
	}
	printf("%d", accumulate(answer.begin(), answer.end(), 0));
	
	return 0;
}