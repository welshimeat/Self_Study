#include <stdio.h>

int main(){
  double student[5];
  for(int i=0; i<5; i++){
    printf("-%d�� �л��� Ű��? ", i+1);
    scanf("%lf", &student[i]);
  }
  printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�.\n", (student[0]+student[1]+student[2]+student[3]+student[4])/5);
  return 0;
}
