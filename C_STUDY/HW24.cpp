#include <stdio.h>

int inputdepth(const char*);
int calculate(int);
void printres(int, int);

int main(){
  int depth, day;
  depth = inputdepth("* 우물의 깊이를 입력하시오(cm단위) : ");
  day = calculate(depth);
  printres(depth, day);
  return 0;
}

int inputdepth(const char* msg){
  int depth;
  printf(msg);
  scanf("%d", &depth);
  return depth;
}

int calculate(int depth){
  int day = 0, current = 0;
  if(current >= depth)
    return day;
  while(1){
    current += 50;
    day++;
    if(current >= depth)
      break;
    current -= 20;
  }
  return day;
}

void printres(int depth, int day){
  printf("%.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", (double)depth/100, day);
}
