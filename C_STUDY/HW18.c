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
  printf("���尴�� ���̸� �Է��Ͻÿ� : ");
  scanf("%d", &age);
  return age;
}

int inputnum(){
  int num;
  printf("���尴�� ���� �Է��Ͻÿ� : ");
  scanf("%d", &num);
  return num;
}

void printres(int fee, int discount){
  printf("\n\n����� => %d��", fee);
  printf("\n���αݾ� => %d��", discount);
  printf("\n�����ݾ� => %d��", fee-discount);
}
