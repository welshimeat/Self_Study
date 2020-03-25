#include <stdio.h>

int main(){
  int num;
  printf("ASCII code값을 입력하시오 : ");
  scanf("%d", &num);
  printf("%d은 '%c'의 ASCII code 입니다.", num, num);
  return 0;
}
