#include <iostream>
#include <string>
#include <set>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
vector<pair<int, int>> v;
string str;
set<string> answer;
bool selected[200];

void DFS(int index, int cnt);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(i);
		}
		else if (str[i] == ')') {
			v.push_back({ s.top(), i });
			s.pop();
		}
	}

	DFS(0, 0);
	for (auto iter = answer.begin(); iter != answer.end(); iter++) {
		cout << *iter << '\n';
	}
	

	return 0;
}

void DFS(int index, int cnt) {
	if (cnt >= 1) {
		string output = "";
		for (int i = 0; i < str.size(); i++) {
			if (!selected[i]) {
				output += str[i];
			}
		}
		answer.insert(output);
	}

	for (int i = index; i < v.size(); i++) {
		selected[v[i].first] = true;
		selected[v[i].second] = true;
		DFS(i + 1, cnt + 1);
		selected[v[i].first] = false;
		selected[v[i].second] = false;
	}
}