#include <stdio.h>

int main(){
  int num, sum=0;
  for(int i=1; i<=5; i++){
    printf("0���� ū���� �Է��Ͻÿ�(%d ��°) : ", i);
    scanf("%d", &num);
    if(num<=0)
      i--;
    else sum += num;
  }
  printf("�Էµ� ���� �� �� : %d\n", sum);
  return 0;
}
