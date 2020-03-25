#include <stdio.h>

int inputyear(const char*);
int yearCheck(int);
void printyear(int, int);

int main(){
  int year, check;
  year = inputyear("�⵵�� �Է��Ͻÿ� : ");
  check = yearCheck(year);
  printyear(year, check);
}

int inputyear(const char* msg){
  int year;
  printf("%s", msg);
  scanf("%d", &year);
  return year;
}

int yearCheck(int year){
  if(year%4 == 0){
    if(year%100 == 0){
      if(year%400 == 0)
        return 1;
      else return 0;
    }
    else return 1;
  }
  else return 0;
}

void printyear(int year, int check){
  if(check == 0)
    printf("%d���� ���(Common year)�Դϴ�.\n", year);
  else
    printf("%d���� ����(Leap year)�Դϴ�.\n", year);
  return;
}
