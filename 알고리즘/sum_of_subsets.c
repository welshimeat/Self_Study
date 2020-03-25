#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define yes 1
#define no 0

int n, W, weight, total, *w, *include;
_Bool promising(int i,int weight, int total);

void sum_of_subsets(int i, int weight, int total){
  if(promising(i,weight,total)){
    if(weight == W)
      for(int k=1; k<=i; k++){
        if(include[k] == 1)
          printf("yes ");
        else if(include[k] == 0)
          printf("no ");
      }
    else{
      include[i+1] = yes;
      sum_of_subsets(i+1, weight+w[i+1], total-w[i+1]);
      include[i+1] = no;
      sum_of_subsets(i+1, weight, total-w[i+1]);
    }
  }
}

_Bool promising(int i,int weight, int total){
  return (weight + total >= W) && (weight == W || weight + w[i+1] <= W);
}

int main(){
  printf("n의 크기를 입력하세요 :");
  scanf("%d",&n);

  w = (int*)malloc((n+1) * sizeof(int));
  include = (int*)malloc((n+1) * sizeof(int));

  printf("\nW의 크기를 입력하세요 :");
  scanf("%d",&W);

  printf("\nw의 원소를 차례대로 입력하세요 :");
  for(int i=1; i<=n; i++)
    scanf("%d",&w[i]);

  for(int k=1; k<=n; k++)
    total += w[k];

  sum_of_subsets(0, 0, total);
}
