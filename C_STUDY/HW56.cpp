#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void randarr(int (*)[5]);
void printarr(int (*)[5]);

int main(){
  int num[5][5];
  srand((unsigned int)time(NULL));
  randarr(num);
  printarr(num);
  return 0;
}

void randarr(int (*num)[5]){
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++){
      num[i][j] = rand()%20+1;
    }
}

void printarr(int (*num)[5]){
  int sum1=0, sum2=0, sum3=0;
  for(int i=0; i<5; i++){
    printf("%d¹ø Çà :", i);
    for(int j=0; j<5; j++){
      printf("%3d", num[i][j]);
      if(i==j) sum1+=num[i][j];
      else if(i<j) sum2+=num[i][j];
      else sum3+=num[i][j];
    }
    printf("\n");
  }
  printf("\nsum1 = %d\nsum2 = %d\nsum3 = %d\n", sum1, sum2, sum3);
  return;
}
