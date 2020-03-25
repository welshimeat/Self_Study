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
  printf("\n1~%d������ �� �Ҽ��� %d�� �Դϴ�.\n", num, prime);
  return 0;
}

int inputNum(){
  int num;
  printf("*������ �ϳ��� �Է��Ͻÿ� : ");
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
