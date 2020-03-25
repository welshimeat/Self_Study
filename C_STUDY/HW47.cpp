#include <stdio.h>

void inputnum(double*);
double mymax(double*);
double mymin(double*);
void printres(double, double);

int main(){
  double num[5], max, min;
  inputnum(num);
  max = mymax(num);
  min = mymin(num);
  printres(max, min);
  return 0;
}

void inputnum(double *num){
  for(int i=0; i<5; i++){
    printf("%d번 방 값 : ", i);
    scanf("%lf", num+i);
    while(getchar() != '\n'){
      while(getchar() != '\n')
        ;
      printf("%d번 방 값 : ", i);
      scanf("%lf", num+i);
    }
  }
  return;
}

double mymax(double *num){
  double max = num[0];
  for(int i=1; i<5; i++)
    if(num[i] > max)
      max = num[i];
  return max;
}

double mymin(double *num){
  double min = num[0];
  for(int i=1; i<5; i++)
    if(num[i] < min)
      min = num[i];
  return min;
}

void printres(double max, double min){
  printf("\n가장 큰 값 : %.2lf\n", max);
  printf("가장 작은 값 : %.2lf\n", min);
  return;
}
