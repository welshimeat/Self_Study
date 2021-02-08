#include <iostream>
using namespace std;

int N, cnt, visited[1001];
char road[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> road[i];
	}

	for (int i = 1; i <= N; i++) {
		bool isExist = false;
		int j = i;
		while (1) {
			if (visited[j] == 0) {
				visited[j] = i;
			}
			else if(visited[j] == i){
				break;
			}
			else {
				isExist = true;
				break;
			}
			
			if (road[j] == 'E') j += 1;
			else j -= 1;
		}
		
		if (!isExist) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
