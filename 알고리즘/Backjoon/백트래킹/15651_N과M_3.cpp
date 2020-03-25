#include <stdio.h>

void solve(int);
int promising(int);
int check[9];
int N, M;

int main(){
  scanf("%d %d", &N, &M);
  solve(0);
  return 0;
}

void solve(int i){
  if(1){
    if(i==M){
      for(int j=1; j<=M; j++)
        printf("%d ", check[j]);
      printf("\n");
    }
    else{
      for(int k=1; k<=N; k++){
        check[i+1] = k;
        solve(i+1);
      }
    }
  }
}

int promising(int i){
  int k=1, Switch=1;
  while(k<i && Switch){
    if(check[i] <= check[k])
      Switch = 0;
    k++;
  }
  return Switch;
}
