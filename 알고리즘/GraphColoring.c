#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n,m,**W, *vcolor;

_Bool promising(int i) {
  int j; _Bool switch_;
  switch_ = true;
  j = 1;
  while(j<i && switch_){
    if(W[i][j] && vcolor[i]==vcolor[j])
      switch_ = false;
    j++;
  }
  return switch_;
}

void m_coloring(int i){
  int color;
  if(promising (i))
    if(i==n){
      for(int i=1; i<=n; i++)
        printf("%d ",vcolor[i]);
      printf("\n");
    }
    else
      for(color=1; color<=m; color++){
        vcolor[i+1] = color;
        m_coloring(i+1);
      }
}

int main(){
  printf("n의 값을 입력하세요 : ");
  scanf("%d", &n);
  printf("\nm의 값을 입력하세요 : ");
  scanf("%d", &m);

  W = (int**)malloc((n+1) * sizeof(int*));
  vcolor = (int*)malloc((n+1) * sizeof(int));
  for(int i=1; i<=n; i++){
    W[i] = (int*)malloc(((n+1) * sizeof(int)));
      for(int j=1; j<=n; j++)
        W[i][j] = 0;
      }

  printf("\nW배열의 값을 차례대로 입력하세요 : \n");
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      scanf("%d", &W[i][j]);
  printf("\n\n결과 : \n");
  m_coloring(0);
}
