#include <stdio.h>
#include <math.h>

int inputNum();
int primeNumber(int number);

int main(){
  int num = inputNum(), prime=0;
  for(int i=2; i<=num; i++){
    if(primeNumber(i) == 1){
      printf("%4d ", i);
      prime++;
      if(prime%5 == 0)
        printf("\n");
    }
  }
  printf("\n1~%d까지의 총 소수는 %d개 입니다.\n", num, prime);
  return 0;
}

int inputNum(){
  int num;
  printf("*정수값 하나를 입력하시오 : ");
  scanf("%d", &num);
  return num;
}

int primeNumber(int number){
  for(int i=2; i<=sqrt(number); i++){
    if(number%i==0)
      return 0;
  }
  return 1;
}
