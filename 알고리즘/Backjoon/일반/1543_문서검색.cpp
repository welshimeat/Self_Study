#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string doc, word;
	int len, index = 0, cnt = 0;

	getline(cin, doc, '\n');
	getline(cin, word, '\n');

	len = word.length();
	while(1){
		index = (int)(doc.find(word, index));
		if (index == -1) break;
		else {
			cnt++;
			index += len;
			if (index > doc.length() - 1) break;
		}
	}
	cout << cnt;

	return 0;
}