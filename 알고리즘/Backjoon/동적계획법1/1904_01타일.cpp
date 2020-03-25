#include <stdio.h>

int main(){
  int N;
  scanf("%d", &N);
  long long tile[N+1] = {1, 1};
  for(int i=2; i<=N; i++){
    tile[i] = tile[i-1] + tile[i-2];
    tile[i] %= 15746;
  }
  printf("%lld", tile[N]);
  return 0;
}
