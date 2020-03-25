#include <stdio.h>

char menu();
int inputInt(const char*);
int deposit(int);
int withdraw(int);

int main(){
  char input;
  int money=0;
  printf("현재 잔액은 0원 입니다.\n\n");
  while(1){
    switch(input = menu()){
      case 'i' : money = deposit(money); break;
      case 'o' : money = withdraw(money); break;
      case 'q' : return 0;
      default : ;
    }
  }
}

char menu(){
  char input;
  printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
  scanf(" %c", &input);
  while((input != 'i') && (input != 'o') && (input != 'q')){
    printf("* 잘못 입력하셨습니다.\n");
    while(getchar() != '\n')
      ;
    printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
    scanf(" %c", &input);
  }
  return input;
}

int inputInt(const char* msg){
  int input;
  printf(msg);
  scanf("%d", &input);
  while(input<0 || getchar() != '\n'){
    printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : ");
    while(getchar() != '\n')
      ;
    scanf("%d", &input);
  }
  return input;
}

int deposit(int money){
  int deposit;
  deposit = inputInt("# 입금액을 입력하세요 : ");
  printf("* 현재 잔액은 %d원 입니다.\n\n", money+=deposit);
  return money;
}

int withdraw(int money){
  int withdraw;
  withdraw = inputInt("# 출금액을 입력하세요 : ");
  if(withdraw>money){
    printf("* 잔액이 부족합니다.\n* 현재 잔액은 %d원 입니다.\n\n", money);
    return money;
  }
  printf("* 현재 잔액은 %d원 입니다.\n\n", money-=withdraw);
  return money;
}
