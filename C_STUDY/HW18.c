#include <stdio.h>
int inputage();
int inputnum();
void printres(int, int);

int main(){
  int age, num, fee, discount = 0;
  age = inputage();
  num = inputnum();

  if(age <= 7)
    fee = 500;
  else if(age >= 8 && age <= 13)
    fee = 700;
  else if(age >= 14 && age <= 19)
    fee = 1000;
  else if(age >= 20 && age <= 55)
    fee = 1500;
  else if(age >= 56)
    fee = 500;

  fee = fee*num;
  if(num >= 5)
    discount = fee * 0.1;

    printres(fee, discount);
}

int inputage(){
  int age;
  printf("입장객의 나이를 입력하시오 : ");
  scanf("%d", &age);
  return age;
}

int inputnum(){
  int num;
  printf("입장객의 수를 입력하시오 : ");
  scanf("%d", &num);
  return num;
}

void printres(int fee, int discount){
  printf("\n\n입장료 => %d원", fee);
  printf("\n할인금액 => %d원", discount);
  printf("\n결제금액 => %d원", fee-discount);
}
