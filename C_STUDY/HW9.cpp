#include <stdio.h>

int inputnum();

int main(){
  int num;
  printf("�������� �Է��ϼ��� : ");
  num = inputnum();
  printf("�Էµ� ���� 8 ������ %#o �Դϴ�.\n", num);
  printf("�Էµ� ���� 16 ������ %#x �Դϴ�.\n", num);
  return 0;
}

int inputnum(){
  int num;
  scanf("%d", &num);
  return num;
}
