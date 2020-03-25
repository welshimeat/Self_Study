#include <stdio.h>

double inputtemp();
void printtemp(double);

int main(){
  double F,C;
  F = inputtemp();
  C = 5.0/9.0 * (F-32);
  printtemp(C);
  return 0;
}

double inputtemp(){
  double F;
  printf("화씨 온도를 입력하세요 : ");
  scanf("%lf", &F);
  return F;
}

void printtemp(double C){
  printf("섭씨 온도는 %.1lf도 입니다.", C);
  return;
}
