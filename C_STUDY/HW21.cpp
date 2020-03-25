#include <stdio.h>

int main(){
  double student[5];
  for(int i=0; i<5; i++){
    printf("-%d번 학생의 키는? ", i+1);
    scanf("%lf", &student[i]);
  }
  printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", (student[0]+student[1]+student[2]+student[3]+student[4])/5);
  return 0;
}
