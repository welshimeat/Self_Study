#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int visited[51], N, input_length;
stack<pair<int, int>> s;
string input;
vector<int> ans;
bool found = false;
void dfs(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;
	input_length = input.size();
	if (input_length < 9) {
		N = input_length;
	}
	else {
		N = 9 + (input_length - 9) / 2;
	}
	dfs(0);

	return 0;
}

void dfs(int index) {
	if (found) return;
	if (index == input_length) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
		found = true;
		return;
	}
	int num = stoi(input.substr(index, 1));
	if (num <= N && !visited[num]) {
		visited[num] = 1;
		ans.push_back(num);
		dfs(index + 1);
		ans.pop_back();
		visited[num] = 0;
	}
	if (index <= input_length - 2) {
		num = stoi(input.substr(index, 2));
		if (num <= N && !visited[num]) {
			visited[num] = 1;
			ans.push_back(num);
			dfs(index + 2);
			ans.pop_back();
			visited[num] = 0;
		}
	}
}