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
  printf("ȭ�� �µ��� �Է��ϼ��� : ");
  scanf("%lf", &F);
  return F;
}

void printtemp(double C){
  printf("���� �µ��� %.1lf�� �Դϴ�.", C);
  return;
}
