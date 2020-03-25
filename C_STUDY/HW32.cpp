#include <stdio.h>

int inputUint(const char*);
double inputDouble(const char*);
int ipow(int, int);
double fpow(double, int);

int main(){
  int num, N;
  double fnum;
  num = inputUint("* 양의 정수 밑을 입력 하시오 : ");
  N = inputUint("* 양의 승을 입력 하시오 : ");
  printf("%d의 %d승은 %d입니다.\n\n", num, N, ipow(num, N));

  fnum = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
  N = inputUint("* 양의 승을 입력 하시오 : ");
  printf("%.2lf의 %d승은 %.3lf 입니다.\n", fnum, N, fpow(fnum, N));
  return 0;
}

int inputUint(const char* msg){
  int num;
  printf(msg);
  scanf("%d", &num);
  while(num <= 0 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
      printf(msg);
      scanf("%d", &num);
  }
  return num;
}

double inputDouble(const char* msg){
  double num;
  printf(msg);
  scanf("%lf", &num);
  while(num <= 0 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf(msg);
    scanf("%lf", &num);
  }
  return num;
}

int ipow(int num, int N){
  int res=1;
  for(int i=0; i<N; i++)
    res *= num;
  return res;
}

double fpow(double fnum, int N){
  double res=1;
  for(int i=0; i<N; i++)
    res *= fnum;
  return res;
}
