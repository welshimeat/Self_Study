#include <stdio.h>

void inputnum(int*, const char*);
int calculate(int, int);
void printres(int, int);

int main(){
  int code, amount;
  inputnum(&code, "* 사용자 코드를 입력하시오(1:가정용/2:상업용/3:공업용) : ");
  inputnum(&amount, "* 사용량을 입력하시오(ton단위) : ");
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
  printf("\n# 사용자코드 : %d", code);
  switch(code){
    case 1 : printf("(가정용)\n"); break;
    case 2 : printf("(상업용)\n"); break;
    case 3 : printf("(공업용)\n");
  }
  printf("# 사용량 : %d ton\n", amount);
  printf("# 총수도요금 : %d원\n", calculate(code, amount));
  return;
}
