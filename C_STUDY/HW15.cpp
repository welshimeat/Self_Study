#include <stdio.h>

double inputnum();
double bmi(int, double);
void printbmi(double);

int main(){
  int weight;
  double height, bminum;
  printf("�����Ը� �Է��ϼ���(kg) : ");
  weight = inputnum();
  printf("Ű�� �Է��ϼ���(m) : ");
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
    printf("����� BMI�� %.1lf���� ��ü���Դϴ�.\n", bminum);
  else if(bminum>=18.5 && bminum<25.0)
    printf("����� BMI�� %.1lf���� ����ü���Դϴ�.\n", bminum);
  else if(bminum>=25.0 && bminum<30.0)
    printf("����� BMI�� %.1lf���� ��ü���Դϴ�.\n", bminum);
  else if(bminum>=30.0 && bminum<40.0)
    printf("����� BMI�� %.1lf���� ���Դϴ�.\n", bminum);
  else
    printf("����� BMI�� %.1lf���� �����Դϴ�.\n", bminum);
  return;
}
