#include <stdio.h>

int inputyear(const char*);
int yearCheck(int);
void printyear(int, int);

int main(){
  int year, check;
  year = inputyear("년도를 입력하시오 : ");
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
    printf("%d년은 평년(Common year)입니다.\n", year);
  else
    printf("%d년은 윤년(Leap year)입니다.\n", year);
  return;
}
