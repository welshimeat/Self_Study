#include <stdio.h>

int inputnum();

int main(){
  int num;
  printf("정수값을 입력하세요 : ");
  num = inputnum();
  printf("입력된 값은 8 진수로 %#o 입니다.\n", num);
  printf("입력된 값은 16 진수로 %#x 입니다.\n", num);
  return 0;
}

int inputnum(){
  int num;
  scanf("%d", &num);
  return num;
}
