#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, **W, *vindex;

_Bool promising(int i){
  int j; _Bool switch_;
  if(i == n-1 && !W[vindex[n-1]][vindex[0]])
    switch_ = false;
  else if(i>0 && !W[vindex[i-1]][vindex[i]])
    switch_ = false;
  else {
    switch_ = true;
    j = 1;
    while(j<i && switch_) {
      if(vindex[i] == vindex[j])
        switch_ = false;
      j++;
    }
  }
  return switch_;
  }

  void hamiltonian(int i) {
    int j;

    if(promising(i))
      if(i == n-1){
        for(int k=1; k<=n-1; k++)
          printf("vindex[%d] = %d\n",k, vindex[k]);
        printf("\n");
      }
      else
        for(j=2; j<=n; j++){
          vindex[i+1] = j;
        hamiltonian(i+1);
      }
  }

  int main(){
    printf("n의 값을 입력하세요 : ");
    scanf("%d", &n);

    W = (int**)malloc((n+1) * sizeof(int*));
    vindex = (int*)malloc((n+1) * sizeof(int));
    for(int i=1; i<=n; i++){
      W[i] = (int*)malloc(((n+1) * sizeof(int)));
        for(int j=1; j<=n; j++)
          W[i][j] = 0;
        }

    printf("\nW배열의 값을 차례대로 입력하세요 : \n");
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        scanf("%d", &W[i][j]);

    vindex[0] = 1;
    printf("\n\n결과 : \n");
    hamiltonian(0);
  }
