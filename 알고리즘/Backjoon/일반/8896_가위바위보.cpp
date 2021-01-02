#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, T, size;
	bool Rflag, Sflag, Pflag;
	string robot[11];

	cin >> T;
	for (int i = 0; i < T; i++) {
		list<int> lt, temp;
		cin >> N;
		for (int j = 1; j <= N; j++) {
			cin >> robot[j];
			lt.push_back(j);
		}
		size = robot[1].length();
		for (int j = 0; j < size; j++) {
			Rflag = false, Sflag = false, Pflag = false;
			for (auto iter = lt.begin(); iter != lt.end(); iter++) {
				if (robot[*iter][j] == 'R') Rflag = true;
				else if (robot[*iter][j] == 'S') Sflag = true;
				else Pflag = true;
			}
			if (Rflag && Sflag && Pflag) {
				continue;
			}
			else if (Rflag && Sflag) {
				temp.assign(lt.begin(), lt.end());
				for (auto iter = lt.begin(); iter != lt.end(); iter++) {
					if (robot[*iter][j] == 'S') {
						temp.remove(*iter);
					}
				}
				lt.assign(temp.begin(), temp.end());
			}
			else if (Sflag && Pflag) {
				temp.assign(lt.begin(), lt.end());
				for (auto iter = lt.begin(); iter != lt.end(); iter++) {
					if (robot[*iter][j] == 'P') {
						temp.remove(*iter);
					}
				}
				lt.assign(temp.begin(), temp.end());
			}
			else if (Pflag && Rflag) {
				temp.assign(lt.begin(), lt.end());
				for (auto iter = lt.begin(); iter != lt.end(); iter++) {
					if (robot[*iter][j] == 'R') {
						temp.remove(*iter);
					}
				}
				lt.assign(temp.begin(), temp.end());
			}
			else continue;

			if (lt.size() == 1) {
				cout << lt.front() << endl;
				break;
			}
		}
		if (lt.size() != 1) {
			cout << 0 << endl;
		}
	}

	return 0;
}

