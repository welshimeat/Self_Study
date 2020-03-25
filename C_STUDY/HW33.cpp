#include <stdio.h>

int menu();
unsigned char openFan(unsigned char);
unsigned char offFan(unsigned char);
unsigned char reverseFan(unsigned char);
void displayFan(unsigned char);

int main(){
  int input;
  unsigned char Fan = 0;
  while(1){
    switch(input = menu()){
      case 1 : Fan = openFan(Fan); displayFan(Fan); break;
      case 2 : Fan = offFan(Fan); displayFan(Fan); break;
      case 3 : Fan = reverseFan(Fan); displayFan(Fan); break;
      case 4 : return 0;
    }
  }
  return 0;
}

int menu(){
  int input;
  printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
  scanf("%d", &input);
  while(input < 1 || input > 4 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
    scanf("%d", &input);
  }
  return input;
}

unsigned char openFan(unsigned char Fan){
  int input;
  unsigned char temp = 1;
  printf("\n--------------------------------------------------------------------\n");
  printf("                      Fan 열기 작업 실행 화면\n");
  printf("--------------------------------------------------------------------\n");
  printf(" * OPEN할 FAN 번호를 입력하시오(1-8) : ");
  scanf("%d", &input);
  while(input < 1 || input > 8 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf(" * OPEN할 FAN 번호를 입력하시오(1-8) : ");
    scanf("%d", &input);
  }
  temp <<= input-1;
  return Fan |= temp;
}

unsigned char offFan(unsigned char Fan){
  int input;
  unsigned char temp = 1;
  printf("\n--------------------------------------------------------------------\n");
  printf("                      Fan 닫기 작업 실행 화면\n");
  printf("--------------------------------------------------------------------\n");
  printf(" * CLOSE할 FAN 번호를 입력하시오(1-8) : ");
  scanf("%d", &input);
  while(input < 1 || input > 8 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf(" * CLOSE할 FAN 번호를 입력하시오(1-8) : ");
    scanf("%d", &input);
  }
  temp <<= input-1;
  return Fan &= ~temp;
}

unsigned char reverseFan(unsigned char Fan){
  printf("\n--------------------------------------------------------------------\n");
  printf("                      Fan 전체 전환 작업 실행 화면\n");
  printf("--------------------------------------------------------------------\n");
  printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
  return ~Fan;
}

void displayFan(unsigned char Fan){
  unsigned char temp = 0x80;
  printf("----------------------------------------------------------\n");
  printf("8번FAN   7번FAN   6번FAN   5번FAN   4번FAN   3번FAN   2번FAN   1번FAN\n");
  for(int i=0; i<8; i++){
    if((temp&Fan)>>(7-i) == 0)
      printf(" OFF     ");
    else
      printf(" ON      ");
    temp >>= 1;
  }
  printf("\n");
}
