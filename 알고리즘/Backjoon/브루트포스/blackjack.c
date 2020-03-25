#include <stdio.h>
#include <stdlib.h>

int main(){
  int N,M,max=0;
  scanf("%d %d",&N, &M);

  int num[N];
  for(int i=0; i<N; i++)
    scanf("%d", num+i);

  for(int i=0; i<N-2; i++)
    for(int j=i+1; j<N-1; j++)
      for(int k=j+1; k<N; k++){
        if(num[i]+num[j]+num[k] > max && num[i]+num[j]+num[k] <= M)
          max = num[i]+num[j]+num[k];
        }

  printf("%d", max);
}
