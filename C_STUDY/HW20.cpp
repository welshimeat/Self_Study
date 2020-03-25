#include <stdio.h>

int inputtime(const char*);
int calculateglosspay(int);
int calculatetaxes(int);
void printres(int, int);

int main(){
  int time, glosspay, taxes;
  time = inputtime("*1주일간의 근무시간을 입력하시오 : ");
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
  printf("# 총수입 : %6d원\n", glosspay);
  printf("# 세  금 : %6d원\n", taxes);
  printf("# 실수입 : %6d원\n", glosspay-taxes);
  return;
}
