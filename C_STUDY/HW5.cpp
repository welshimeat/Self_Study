#include <stdio.h>

int inputkw();
void printfee(double);

int main(){
  int kw;
  double totalfee, resultfee;
  kw = inputkw();

  totalfee = 660 + 88.5 * kw;
  resultfee = totalfee * 1.09;

  printfee(resultfee);
  return 0;
}

int inputkw(){
  int kw;
  printf("전기 사용량을 입력하세요(kw) : ");
  scanf("%d", &kw);
  return kw;
}

void printfee(double resultfee){
  printf("전기 사용요금은 %lf 원 입니다.\n", resultfee);
  return;
}
