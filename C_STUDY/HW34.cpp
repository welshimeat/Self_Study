#include <stdio.h>

void inputnum(int*, const char*);
int calculate(int, int);
void printres(int, int);

int main(){
  int code, amount;
  inputnum(&code, "* ����� �ڵ带 �Է��Ͻÿ�(1:������/2:�����/3:������) : ");
  inputnum(&amount, "* ��뷮�� �Է��Ͻÿ�(ton����) : ");
  printres(code, amount);
  return 0;
}

void inputnum(int* num, const char* msg){
  printf(msg);
  scanf("%d", num);
  while(getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf(msg);
    scanf("%d", num);
  }
  return;
}

int calculate(int code, int amount){
  int price;
  switch(code) {
    case 1 : price = 50; break;
    case 2 : price = 45; break;
    case 3 : price = 30;
  }
  return 1.05 * amount * price;
}

void printres(int code, int amount){
  printf("\n# ������ڵ� : %d", code);
  switch(code){
    case 1 : printf("(������)\n"); break;
    case 2 : printf("(�����)\n"); break;
    case 3 : printf("(������)\n");
  }
  printf("# ��뷮 : %d ton\n", amount);
  printf("# �Ѽ������ : %d��\n", calculate(code, amount));
  return;
}
