#include <stdio.h>

int main(){
  int lec1, lec2, lec3;
  printf("역사, 문학, 예능 점수를 입력하세요 : ");
  scanf("%d %d %d", &lec1, &lec2, &lec3);
  printf("총점은 %d 이고 평균은 %.2lf 입니다.", lec1+lec2+lec3, (lec1+lec2+lec3)/3.0);
  return 0;
}
