#include <stdio.h>

int main(){
  int iday, hour, min;
  double temp, sec, day = 365.2422;

  temp = day;
  iday = (int)day;
  day -= iday;
  hour = day * 24;
  day = day * 24 - hour;
  min = day * 60;
  day = day * 60 - min;
  sec = day * 60;

  printf("%.4lf���� %d�� %d�ð� %d�� %.2lf���Դϴ�.\n", temp, iday, hour, min, sec);
  return 0;
}
