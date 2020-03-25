#include <stdio.h>
#include <stdlib.h>

int N, **S, min = 1000000000, *start, *link;
void solve(int);
int promising(int);
int calculate();

int main(){
  scanf("%d", &N);
  start = (int*)malloc((N/2+1) * sizeof(int));
  link = (int*)malloc((N/2+1) * sizeof(int));
  S = (int**)malloc(N * sizeof(int*));
  for(int i=0; i<N; i++)
    S[i] = (int*)malloc(N * sizeof(int));
  for(int i=0; i<N; i++)
    for(int j=0; j<N; j++)
      scanf("%d", &S[i][j]);
  solve(0);
  printf("%d\n", min);
  return 0;
}

void solve(int i){
  if(promising(i)){
    if(i==N/2){
      int gap;
      gap = calculate();
      if(min>gap)
        min = gap;
    }
    else{
      for(int j=1; j<=N; j++){
        start[i+1] = j;
        solve(i+1);
      }
    }
  }
}

int promising(int i){
  int k=1, Switch=1;
  while(k<i && Switch){
    if(start[k] == start[i])
      Switch = 0;
    k++;
  }
  return Switch;
}

int calculate(){
  int num=1, linktotal=0, starttotal=0;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=N/2; j++){
      if(i == start[j]){
        break;
      }
      if(j==N/2 && i != start[j]){
        link[num] = i;
        num++;
      }
    }
  for(int i=1; i<=N/2; i++)
    for(int j=1; j<=N/2; j++){
      linktotal += S[link[i]-1][link[j]-1];
      starttotal += S[start[i]-1][start[j]-1];
    }
  if(linktotal >= starttotal)
    return linktotal - starttotal;
  else return starttotal - linktotal;
}
