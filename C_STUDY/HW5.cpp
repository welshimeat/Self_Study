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
  printf("���� ��뷮�� �Է��ϼ���(kw) : ");
  scanf("%d", &kw);
  return kw;
}

void printfee(double resultfee){
  printf("���� ������� %lf �� �Դϴ�.\n", resultfee);
  return;
}
