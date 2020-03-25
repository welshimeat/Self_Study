#include <stdio.h>

int main(){
  int line;
  while(1){
    printf("# 출력 라인수를 입력하시오 : ");
    scanf("%d", &line);
    if(getchar() != '\n')
      return 0;
    for(int i=0; i<line; i++){
      for(int j=0; j<=i; j++)
        printf("*");
      for(int j=0; j<=60-2*i; j++)
        printf(" ");
      for(int j=0; j<=i; j++)
        printf("*");
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
