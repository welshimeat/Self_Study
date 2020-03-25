#include <stdio.h>
#include <stdlib.h>

typedef struct set_of_edge {
	int i;
	int j;
}set_of_edge;

void add(int n, set_of_edge e, set_of_edge* F) {
	for (int k = 0; k < n; k++)
		if (F[k].i == 0) {
			F[k] = e;
			break;
		}
}

void dijkstra(int n, const int** W, set_of_edge* F){
  int i, vnear, min;
  set_of_edge e;
  int* touch;
  int* length;

  touch = (int*)malloc((n+1) * sizeof(int));
  length = (int*)malloc((n+1) * sizeof(int));

  for (int k = 0; k < n; k++) {
    F[k].i = 0;
    F[k].j = 0;
  }

  for(i=2; i<=n; i++){
    touch[i] = 1;
    length[i] = W[1][i];
  }

  for(int k=1; k<=n-1; k++){
    min = 10000;
    for(i=2; i<=n; i++)
      if(length[i]>=0 && length[i]<=min){
        min = length[i];
        vnear = i;
      }
    e.i = touch[vnear];
    e.j = vnear;
    add(n,e,F);
    for(i=2; i<=n; i++)
      if(length[vnear] + W[vnear][i] < length[i]){
        length[i] = length[vnear] + W[vnear][i];
        touch[i] = vnear;
			}
    length[vnear] = -1;
    }
}



int main(){
  int** W;
  set_of_edge* F;
  int n;

  printf("Vertex의 갯수를 입력하세요 : ");
  scanf("%d", &n);

  F = (set_of_edge*)malloc(n * (sizeof(set_of_edge)));
  W = (int**)malloc(n * sizeof(int*));
  for(int i=1; i<=n; i++)
  W[i] = (int*)malloc(n * sizeof(int));

  printf("\nW배열을 1행 1열부터 차례대로 입력하세요 : \n");
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      scanf("%d",&W[i][j]);

  dijkstra(n, W, F);

  for (int k = 0; k < n - 1; k++)
		printf("(v%d, v%d) \n", F[k].i, F[k].j);



}
