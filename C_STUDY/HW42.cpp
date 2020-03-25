#include <stdio.h>

int main(){
  printf("<2중 for문을 이용한 출력>\n");
  for(int i=1; i<10; i++){
    for(int j=2; j<6; j++){
      printf("%d*%d =%2d\t\t\t", j, i, j*i);
    }
    printf("\n");
  }
  printf("\n");
  for(int i=1; i<10; i++){
    for(int j=6; j<10; j++){
      printf("%d*%d =%2d\t\t\t", j, i, j*i);
    }
    printf("\n");
  }
  printf("----------------------------------------------------------------------------\n");
  printf("\n<3중 for문을 이용한 출력>\n");
  for(int k=0; k<=4; k+=4){
    for(int i=1; i<10; i++){
      for(int j=2; j<6; j++){
        printf("%d*%d =%2d\t\t\t", j+k, i, (j+k)*i);
      }
      printf("\n");
  }
  printf("\n");
  }
  return 0;
}
