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
  printf("현재 당신의 소유 금액 입력 : ");
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
          printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", i, j, k);
        }
      }
  printf("어떻게 구입하시겠습니까?\n\n");
}
