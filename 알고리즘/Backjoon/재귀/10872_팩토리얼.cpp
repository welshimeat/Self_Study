#include <stdio.h>

int factorial(int num);

int main(){
  int num;
  scanf("%d", &num);
  printf("%d", factorial(num));
  return 0;
}

int factorial(int num){
  if(num==0) return 1;
  else if(num==1) return 1;
  else return num*factorial(num-1);
}
