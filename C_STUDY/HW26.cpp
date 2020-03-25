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
  printf("게임결과 : %d 승 %d 무\n", win, draw);
  return 0;
}

int inputnum(){
  int user;
  printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
  scanf("%d", &user);
  while(user<1 || user>3 || getchar() != '\n'){
    myflush();
    printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
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
      case 1 : printf("  당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n"); break;
      case 2 : printf("  당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n"); break;
      case 3 : printf("  당신은 바위 선택, 컴퓨터는 보 선택 : 당신이 졌습니다.\n"); break;
    }
  }
  else if(user == 2){
    switch(com){
      case 1 : printf("  당신은 가위 선택, 컴퓨터는 바위 선택 : 당신이 졌습니다.\n"); break;
      case 2 : printf("  당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n"); break;
      case 3 : printf("  당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n"); break;
    }
  }
  else if(user == 3){
    switch(com){
      case 1 : printf("  당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n"); break;
      case 2 : printf("  당신은 보 선택, 컴퓨터는 가위 선택 : 당신이 졌습니다.\n"); break;
      case 3 : printf("  당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다..\n"); break;
    }
  }
}
