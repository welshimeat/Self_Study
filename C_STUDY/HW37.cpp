#include <stdio.h>

int inputnum();

int main(){
  int day, total=0, repeat=0, i=1;
  day = inputnum();
  while(1){
    for(int j=1; j<=i; j++){
      repeat++;
      if(repeat > day)
        break;
      total += i;
    }
    if(repeat > day)
      break;
    i++;
  }

  printf("�ٹ��� : %d �� / �� ��ȭ �� : %d��\n", day, total);
  return 0;
}

int inputnum(){
  int num;
  printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
  scanf("%d", &num);
  while(getchar() != '\n'){
    while(getchar() != '\n')
      ;
      printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
    scanf("%d", &num);
  }
  return num;
}
