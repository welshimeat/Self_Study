#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputnum();
void myflush();
void printres(int, int);

int main(){
  int user, com, win=0, draw=0;
  srand((unsigned int)time(NULL));
  while(1){
    user = inputnum();
    com = rand()%3 +1;
    printres(user, com);
    if(user == com)
      draw++;
    else if((user==1 && com==2) || (user==2 && com==3) || (user==3 && com==1))
      win++;
    else break;
  }
  printf("���Ӱ�� : %d �� %d ��\n", win, draw);
  return 0;
}

int inputnum(){
  int user;
  printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
  scanf("%d", &user);
  while(user<1 || user>3 || getchar() != '\n'){
    myflush();
    printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
    scanf("%d", &user);
  }
  return user;
}

void myflush(){
  while(getchar() != '\n')
  ;
}

void printres(int user, int com){
  if(user == 1){
    switch(com){
      case 1 : printf("  ����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n"); break;
      case 2 : printf("  ����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n"); break;
      case 3 : printf("  ����� ���� ����, ��ǻ�ʹ� �� ���� : ����� �����ϴ�.\n"); break;
    }
  }
  else if(user == 2){
    switch(com){
      case 1 : printf("  ����� ���� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n"); break;
      case 2 : printf("  ����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n"); break;
      case 3 : printf("  ����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n"); break;
    }
  }
  else if(user == 3){
    switch(com){
      case 1 : printf("  ����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n"); break;
      case 2 : printf("  ����� �� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n"); break;
      case 3 : printf("  ����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�..\n"); break;
    }
  }
}
