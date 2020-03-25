#include <stdio.h>

int main(){
  int money = 278970;
  int m50000, m10000, m5000, m1000, m500, m100, m50, m10;
  m50000 = money/50000;
  money = money - m50000*50000;
  m10000 = money/10000;
  money = money - m10000*10000;
  m5000 = money/5000;
  money = money - m5000*5000;
  m1000 = money/1000;
  money = money - m1000*1000;
  m500 = money/500;
  money = money - m500*500;
  m100 = money/100;
  money = money - m100*100;
  m50 = money/50;
  money = money - m50*50;
  m10 = money/10;
  money = money - m10*10;

  printf("50000원권 : %d\n10000원권 : %d\n5000원권 : %d\n1000원권 : %d\n500원권 : %d\n100원권 : %d\n50원권 : %d\n10원권 : %d\n", m50000, m10000, m5000, m1000, m500, m100, m50, m10);
}
