#include <stdio.h>

int inputtime(const char*);
int calculateglosspay(int);
int calculatetaxes(int);
void printres(int, int);

int main(){
  int time, glosspay, taxes;
  time = inputtime("*1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
  glosspay = calculateglosspay(time);
  taxes = calculatetaxes(glosspay);
  printres(glosspay, taxes);
  return 0;
}

int inputtime(const char* msg){
  int time;
  printf("%s", msg);
  scanf("%d", &time);
  return time;
}

int calculateglosspay(int time){
  int glosspay;
  if(time>=40)
    glosspay = 40*3000 + (time-40)*4500;
  else
    glosspay = time*3000;
  return glosspay;
}

int calculatetaxes(int glosspay){
  int taxes;
  if(glosspay>=100000)
    taxes = 15000 + (glosspay-100000)*0.25;
  else
    taxes = glosspay*0.15;
  return taxes;
}

void printres(int glosspay, int taxes){
  printf("# �Ѽ��� : %6d��\n", glosspay);
  printf("# ��  �� : %6d��\n", taxes);
  printf("# �Ǽ��� : %6d��\n", glosspay-taxes);
  return;
}
