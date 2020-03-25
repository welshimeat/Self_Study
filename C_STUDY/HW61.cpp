#include <stdio.h>
#include <windows.h>

#define BLACK 0
#define LIGHTGRAY 7
#define LIGHTBLUE 9
#define LIGHTRED 12


void printcalender(int, int);
int yearCheck(int);
int calculateday(int, int, int);
void textcolor(int, int);

int main(){
  char input;
  int year = 2020, month = 1;
  printcalender(year, month);
  while((input = getchar()) != 'q'){
    switch(input){
      case 'w' : printcalender(--year, month); break;
      case 's' : printcalender(++year, month); break;
      case 'a' : if(month == 1){
        year--;
        month = 12;
        printcalender(year, month);
      }
      else
        printcalender(year, --month);
      break;
      case 'd' : if(month == 12){
        year++;
        month = 1;
        printcalender(year, month);
      }
      else
        printcalender(year, ++month);
      break;
      }
  }
  return 0;
}

void printcalender(int year, int month){
  int cnt=0;
  int day = calculateday(year, month, 1)%7;
  int month2day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(yearCheck(year)==1) month2day[1] = 29;
  printf("                             [ %d  . %2d ]\n\n", year, month);
  printf("              SUN   MON   TUE   WED   THU   FRI   SAT\n");
  printf("         ------------------------------------------------------\n              ");
  for(int i=0; i<day; i++){
    printf("      ");
    cnt++;
  }
  for(int i=1; i<=month2day[month-1]; i++){
    if(cnt%7==0)
      textcolor(LIGHTRED, BLACK);
    else if(cnt%7==6)
      textcolor(LIGHTBLUE, BLACK);
    else
      textcolor(LIGHTGRAY, BLACK);
    printf("%3d   ", i);
    cnt++;
    if(cnt%7==0)
      printf("\n              ");
  }
  textcolor(LIGHTGRAY, BLACK);
  printf("\nw : 전 년도 /s : 다음 년도 /a : 전 월 /d : 다음 월 /q : 종료\n");
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

void textcolor(int foreground, int background){
  int color = foreground + background*16;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
