#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputnum(int, int);
void printmsg(int, int);
void myflush();

int main(){
  srand((unsigned int)time(NULL));
  int num, res, i=0, min=0, max=101;
  res = rand() % 100 + 1;
  while(1){
    num = inputnum(min, max);
    i++;
    if(num == res) break;
    else if(res>num){
      min = num;
      printmsg(min, max);
    }
    else{
      max = num;
      printmsg(min, max);
    }
  }
  printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.", i);
  return 0;
}

int inputnum(int min, int max){
  int num;
  printf("# 숫자를 입력하시오 : ");
  scanf("%d", &num);
  while(num<=min || num>=max || getchar() != '\n'){
    myflush();
    printf("# 숫자를 입력하시오 : ");
    scanf("%d", &num);
  }
  return num;
}

void printmsg(int min, int max){
    printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
}

void myflush(){
  while(getchar() != '\n')
    ;
}
