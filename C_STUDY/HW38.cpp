#include <stdio.h>

int inputmoney();
void printselection(int);

int main(){
  int money;
  while(1){
    money = inputmoney();
    if(getchar() != '\n')
      return 0;
    printselection(money);
  }
  return 0;
}

int inputmoney(){
  int money;
  printf("���� ����� ���� �ݾ� �Է� : ");
  scanf("%d", &money);
  return money;
}

void printselection(int money){
  int total;
  for(int i=1; i<money/500; i++)
    for(int j=1; j<money/700; j++)
      for(int k=1; k<money/400; k++){
        total = 500*i + 700*j + 400*k;
        if(total == money){
          printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", i, j, k);
        }
      }
  printf("��� �����Ͻðڽ��ϱ�?\n\n");
}
