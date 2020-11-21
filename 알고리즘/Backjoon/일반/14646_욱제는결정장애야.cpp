#pragma warning(disable:4996)
#include <iostream>

using namespace std;

int main() {
	int N, num, sticker = 0, max = 0;
	bool menu[100001] = { 0 };

	scanf("%d", &N);
	for(int i=0; i<2*N; i++){
		scanf("%d", &num);
		if (!menu[num]) {
			sticker++;
			if (sticker > max) {
				max = sticker;
			}
			menu[num] = true;
		}
		else {
			sticker--;
		}
	}
	printf("%d", max);
	return 0;
}