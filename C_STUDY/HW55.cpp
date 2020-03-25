#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randarr(int (*)[4]);
void printarr(int (*)[4]);

int main(){
  int num[3][4];
  srand((unsigned int)time(NULL));
  randarr(num);
  printarr(num);
  return 0;
}

void randarr(int (*num)[4]){
  for(int i=0; i<3; i++)
    for(int j=0; j<4; j++){
      num[i][j] = rand()%9+1;
    }
}

void printarr(int (*num)[4]){
  int rowtotal[3]={0}, columntotal[4]={0};
  for(int i=0; i<3; i++){
    printf("%d행     :", i);
    for(int j=0; j<4; j++){
      printf("%3d", num[i][j]);
      rowtotal[i] += num[i][j];
      columntotal[j] += num[i][j];
    }
    printf("      %d 행의 합 : %d\n", i, rowtotal[i]);
  }
    printf("열의 합 :");
  for(int i=0; i<4; i++)
  printf("%3d", columntotal[i]);
  return;
}
