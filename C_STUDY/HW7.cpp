#include <stdio.h>

int main(){
  int hour, min;
  double distance, speed, sec;
  printf("�Ÿ��� �Է��Ͻÿ�(km����) : ");
  scanf("%lf", &distance);
  printf("�ü��� �Է��Ͻÿ�(km/h����) : ");
  scanf("%lf", &speed);
  hour = distance/speed;
  min = (distance/speed - hour) * 60;
  sec = (distance/speed - hour - min/60.0) * 3600;

  printf("%.2lfkm = >%d�ð� %d�� %.3lf �� �ҿ��", distance, hour, min, sec);
  return 0;
}
