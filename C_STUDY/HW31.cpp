#include <stdio.h>

char menu();
int inputInt(const char*);
int deposit(int);
int withdraw(int);

int main(){
  char input;
  int money=0;
  printf("���� �ܾ��� 0�� �Դϴ�.\n\n");
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
  printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
  scanf(" %c", &input);
  while((input != 'i') && (input != 'o') && (input != 'q')){
    printf("* �߸� �Է��ϼ̽��ϴ�.\n");
    while(getchar() != '\n')
      ;
    printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
    scanf(" %c", &input);
  }
  return input;
}

int inputInt(const char* msg){
  int input;
  printf(msg);
  scanf("%d", &input);
  while(input<0 || getchar() != '\n'){
    printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
    while(getchar() != '\n')
      ;
    scanf("%d", &input);
  }
  return input;
}

int deposit(int money){
  int deposit;
  deposit = inputInt("# �Աݾ��� �Է��ϼ��� : ");
  printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", money+=deposit);
  return money;
}

int withdraw(int money){
  int withdraw;
  withdraw = inputInt("# ��ݾ��� �Է��ϼ��� : ");
  if(withdraw>money){
    printf("* �ܾ��� �����մϴ�.\n* ���� �ܾ��� %d�� �Դϴ�.\n\n", money);
    return money;
  }
  printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", money-=withdraw);
  return money;
}
