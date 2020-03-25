#include <stdio.h>

int inputUInt();
void myflush();
int transNumber(int);
void printres(int, int, int);

int main(){
  int P1, P2, N;
  printf("시작 값(P1) : ");
  P1 = inputUInt();
  printf("끝 값(P2) : ");
  P2 = inputUInt();
  printf("고집수 : ");
  N = inputUInt();
  printres(P1, P2, N);
  return 0;
}

int inputUInt(){
  int num;
  scanf("%d", &num);
  while(num < 0 || getchar() != '\n'){
    myflush();
    scanf("%d", &num);
  }
  return num;
}

void myflush(){
  while(getchar() != '\n')
    ;
}

int transNumber(int num){
  int a,b,c,d, res;
  if(num<100){
    a = num%10;
    b = num/10%10;
    res = a*b;
  }
  else if(num<1000){
    a = num%10;
    b = num/10%10;
    c = num/100;
    res = a*b*c;
  }
  else{
    a = num%10;
    b = num/10%10;
    c = num/100%10;
    d = num/1000;
    res = a*b*c*d;
  }
  return res;
}

void printres(int P1, int P2, int N){
  int i, num, total=0;
  printf("고집수가 %d인 숫자 출력\n", N);
  for(;P1<=P2;P1++){
    i=0;
    num = P1;
    while(1){
      num = transNumber(num);
      i++;
      if(num<10 || (num>10 && i>=N))
        break;
    }
    if(num<10 && i == N){
      total++;
      printf("%d\n", P1);
    }
  }
  printf("총 개수 : %d개\n", total);
}
