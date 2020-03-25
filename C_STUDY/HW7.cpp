#include <stdio.h>

int main(){
  int hour, min;
  double distance, speed, sec;
  printf("거리를 입력하시오(km단위) : ");
  scanf("%lf", &distance);
  printf("시속을 입력하시오(km/h단위) : ");
  scanf("%lf", &speed);
  hour = distance/speed;
  min = (distance/speed - hour) * 60;
  sec = (distance/speed - hour - min/60.0) * 3600;

  printf("%.2lfkm = >%d시간 %d분 %.3lf 초 소요됨", distance, hour, min, sec);
  return 0;
}
