#include <stdio.h>

int main(){
  int time = 54321;
  int hour, minute, second, temp;
  hour = time/3600;
  temp = time - hour*3600;
  minute = temp/60;
  temp = temp - minute*60;
  second = temp;

  printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�.", time, hour, minute, second);
}
