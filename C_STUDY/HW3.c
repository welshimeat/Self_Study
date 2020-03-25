#include <stdio.h>

int main(){
  int time = 54321;
  int hour, minute, second, temp;
  hour = time/3600;
  temp = time - hour*3600;
  minute = temp/60;
  temp = temp - minute*60;
  second = temp;

  printf("%d초는 %d시간 %d분 %d초 입니다.", time, hour, minute, second);
}
