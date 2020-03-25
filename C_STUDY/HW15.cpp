#include <stdio.h>

double inputnum();
double bmi(int, double);
void printbmi(double);

int main(){
  int weight;
  double height, bminum;
  printf("몸무게를 입력하세요(kg) : ");
  weight = inputnum();
  printf("키를 입력하세요(m) : ");
  height = inputnum();
  bminum = bmi(weight, height);
  printbmi(bminum);
  return 0;
}

double inputnum(){
  double num;
  scanf("%lf", &num);
  return num;
}

double bmi(int weight, double height){
  double bmi = weight/(height*height);
  return bmi;
}

void printbmi(double bminum){
  if(bminum<18.5)
    printf("당신의 BMI는 %.1lf으로 저체중입니다.\n", bminum);
  else if(bminum>=18.5 && bminum<25.0)
    printf("당신의 BMI는 %.1lf으로 정상체중입니다.\n", bminum);
  else if(bminum>=25.0 && bminum<30.0)
    printf("당신의 BMI는 %.1lf으로 과체중입니다.\n", bminum);
  else if(bminum>=30.0 && bminum<40.0)
    printf("당신의 BMI는 %.1lf으로 비만입니다.\n", bminum);
  else
    printf("당신의 BMI는 %.1lf으로 고도비만입니다.\n", bminum);
  return;
}
