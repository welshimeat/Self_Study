#include <stdio.h>

int main(){
  int line;
  while(1){
    printf("# ��� ���μ��� �Է��Ͻÿ� : ");
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
