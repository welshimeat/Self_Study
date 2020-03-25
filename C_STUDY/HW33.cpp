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
  printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
  scanf("%d", &input);
  while(input < 1 || input > 4 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
    scanf("%d", &input);
  }
  return input;
}

unsigned char openFan(unsigned char Fan){
  int input;
  unsigned char temp = 1;
  printf("\n--------------------------------------------------------------------\n");
  printf("                      Fan ���� �۾� ���� ȭ��\n");
  printf("--------------------------------------------------------------------\n");
  printf(" * OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
  scanf("%d", &input);
  while(input < 1 || input > 8 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf(" * OPEN�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
    scanf("%d", &input);
  }
  temp <<= input-1;
  return Fan |= temp;
}

unsigned char offFan(unsigned char Fan){
  int input;
  unsigned char temp = 1;
  printf("\n--------------------------------------------------------------------\n");
  printf("                      Fan �ݱ� �۾� ���� ȭ��\n");
  printf("--------------------------------------------------------------------\n");
  printf(" * CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
  scanf("%d", &input);
  while(input < 1 || input > 8 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf(" * CLOSE�� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
    scanf("%d", &input);
  }
  temp <<= input-1;
  return Fan &= ~temp;
}

unsigned char reverseFan(unsigned char Fan){
  printf("\n--------------------------------------------------------------------\n");
  printf("                      Fan ��ü ��ȯ �۾� ���� ȭ��\n");
  printf("--------------------------------------------------------------------\n");
  printf("��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�. (ON, OFF ���� �ڹٲ�)\n");
  return ~Fan;
}

void displayFan(unsigned char Fan){
  unsigned char temp = 0x80;
  printf("----------------------------------------------------------\n");
  printf("8��FAN   7��FAN   6��FAN   5��FAN   4��FAN   3��FAN   2��FAN   1��FAN\n");
  for(int i=0; i<8; i++){
    if((temp&Fan)>>(7-i) == 0)
      printf(" OFF     ");
    else
      printf(" ON      ");
    temp >>= 1;
  }
  printf("\n");
}
