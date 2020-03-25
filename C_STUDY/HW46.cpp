#include <stdio.h>

int inputdate(int*, int*, int*);
int errorCheck(int, int, int);
int yearCheck(int);
int calculateday(int, int, int);
void printres(int, int, int);

int main(){
  int year, month, day;
  while(inputdate(&year, &month, &day) == 0)
    printres(year, month, day);
  return 0;
}

int inputdate(int* year, int* month, int* day){
  printf("* 년 월 일을 입력하시오 : ");
  if(scanf("%d %d %d", year, month, day) < 3)
    return 1;
  else{
    while(errorCheck(*year, *month, *day) == 1){
      while(getchar() != '\n')
        ;
      printf("* 년 월 일을 입력하시오 : ");
      if(scanf("%d %d %d", year, month, day) < 3)
        return 1;
    }
    return 0;
  }
}

int errorCheck(int year, int month, int day){
  if(year<0)
    return 1;
  else if(month>12 || month<0)
    return 1;
  else if(day<0 || day>31)
    return 1;
  else if((yearCheck(year)==0 && month==2 && day>28) || (yearCheck(year)==1 && month==2 && day>29))
    return 1;
  else return 0;
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

int calculateday(int year, int month, int day){
  int month2day = 0, year2day = 0;
  for(int i=1900; i<year; i++){
    if(yearCheck(i) == 1)
      year2day += 366;
    else year2day += 365;
  }
  switch(month){
    case 12 : month2day += 30;
    case 11 : month2day += 31;
    case 10 : month2day += 30;
    case 9 : month2day += 31;
    case 8 : month2day += 31;
    case 7 : month2day += 30;
    case 6 : month2day += 31;
    case 5 : month2day += 30;
    case 4 : month2day += 31;
    case 3 :if(yearCheck(year)==1) month2day +=29; else month2day +=28;
    case 2 : month2day += 31;
    case 1 : ;
  }
  return year2day + month2day + day;
}

void printres(int year, int month, int day){
  switch(calculateday(year, month, day)%7){
    case 0 :  printf("  %d년 %d월 %d일은 일요일입니다.\n", year, month, day); break;
    case 1 :  printf("  %d년 %d월 %d일은 월요일입니다.\n", year, month, day); break;
    case 2 :  printf("  %d년 %d월 %d일은 화요일입니다.\n", year, month, day); break;
    case 3 :  printf("  %d년 %d월 %d일은 수요일입니다.\n", year, month, day); break;
    case 4 :  printf("  %d년 %d월 %d일은 목요일입니다.\n", year, month, day); break;
    case 6 :  printf("  %d년 %d월 %d일은 토요일입니다.\n", year, month, day); break;
    case 5 :  printf("  %d년 %d월 %d일은 금요일입니다.\n", year, month, day); break;
    default : ;
  }
  return;
}
