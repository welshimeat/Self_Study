#include <stdio.h>

int main(){
  int lec1, lec2, lec3;
  printf("����, ����, ���� ������ �Է��ϼ��� : ");
  scanf("%d %d %d", &lec1, &lec2, &lec3);
  printf("������ %d �̰� ����� %.2lf �Դϴ�.", lec1+lec2+lec3, (lec1+lec2+lec3)/3.0);
  return 0;
}
