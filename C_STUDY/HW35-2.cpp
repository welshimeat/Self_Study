#include <stdio.h>

int main(){
  int num;
  for(int i=0; i<=9; i++){
    for(int j=1; j<=10; j++){
      num = 10*i + j;
      if(num%3==0 && num%5==0)
        printf("%-5d", num);
      else if(num%3 == 0)
        printf("*    ");
      else if(num%5 == 0)
        printf("#    ");
      else printf("%-5d", num);
    }
    printf("\n");
  }
  return 0;
}
