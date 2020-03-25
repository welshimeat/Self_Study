#include <stdio.h>

int main(){
  int T;
  scanf("%d", &T);
  int N[T];
  long long P[101] = {0,1,1,1,2,2,3,4,5,7,9};
  for(int i=0; i<T; i++)
    scanf("%d", &N[i]);
  for(int i=0; i<T; i++){
    for(int j=11; j<=N[i]; j++){
      P[j] = P[j-2]+P[j-3];
    }
  }
  for(int i=0; i<T; i++)
    printf("%lld\n", P[N[i]]);
  return 0;
}
