#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

vector<int> v;
vector<int> freq;
int pos[4001], neg[4001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num, total = 0, max = 0;
	bool duplicated;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
		total += num;
		if (num >= 0) pos[num]++;
		else neg[-num]++;
	}
	sort(v.begin(), v.end());
	
	cout << round(total / (double)N) << '\n';
	cout << v[N/2] << '\n';

	for (int i = 0; i < 4001; i++) {
		if (pos[i]){
			if (pos[i] > max) {
				freq.clear();
				freq.push_back(i);
				max = pos[i];
			}
			else if (pos[i] == max) {
				freq.push_back(i);
			}
		}
	}
	for (int i = 1; i < 4001; i++) {
		if (neg[i]) {
			if (neg[i] > max) {
				freq.clear();
				freq.push_back(-i);
				max = neg[i];
			}
			else if (neg[i] == max) {
				freq.push_back(-i);
			}
		}
	}
	if(freq.size() > 1){
		sort(freq.begin(), freq.end());
		cout << freq[1] << '\n';
	}
	else {
		cout << freq[0] << '\n';
	}
	cout << v[N-1] - v[0] << '\n';

	return 0;
}