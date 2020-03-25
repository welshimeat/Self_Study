#include <stdio.h>

int inputnum();
void printres(int);

int main(){
  int num;
  num = inputnum();
  printres(num);
  return 0;
}

int inputnum(){
  int num;
  printf("* 10진수 정수를 입력하시오 : ");
  scanf("%d", &num);
  while(getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("* 10진수 정수를 입력하시오 : ");
    scanf("%d", &num);
  }
  return num;
}

void printres(int num){
  unsigned int mask = 0x80000000, temp;
  printf("%d(10) = ", num);
  for(int i=1; i<=32; i++){
    temp = mask&num;
    temp >>= 32-i;
    printf("%u", temp);
    mask >>= 1;
  }
  printf("(2)");
  return;
}
