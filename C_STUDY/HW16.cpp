#include <stdio.h>

int inputnum();
int calculate(int);
void print(int);

int main(){
  int num, fee;
  printf("역수를 입력하시오 : ");
  num = inputnum();
  fee = calculate(num);
  print(fee);
  return 0;
}

int inputnum(){
  int num;
  scanf("%d", &num);
  return num;
}

int calculate(int num){
  int fee;
  if(num<=5)
    fee = 600;
  else if(num>=6 && num<=10)
    fee = 800;
  else if(num>10)
    fee = 800 + (num-9)/2*100;
  return fee;
}

void print(int fee){
  printf("요금 : %d원\n", fee);
  return;
}
