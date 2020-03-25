#include <stdio.h>
#include <math.h>

void queen(int);
int promising(int);
int N, res, location[16];

int main(){
  scanf("%d", &N);
  queen(0);
  printf("%d\n", res);
}

void queen(int i){
  if(promising(i)){
    if(i==N) res++;
    else{
      for(int j=1; j<=N; j++){
        location[i+1] = j;
        queen(i+1);
      }
    }
  }
}

int promising(int i){
  int k=1, Switch=1;
  while(k<i && Switch){
    if(location[k] == location[i] || abs(k-i) == abs(location[k]-location[i])) Switch = 0;
    k++;
  }
  return Switch;
}
