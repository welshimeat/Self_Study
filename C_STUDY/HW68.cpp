#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int menuInput();
void practiceGame();
void VSGame();
int** makeBingo(int);
int isDuplicate(int **, int, int, int);
void printPractice(int **, int);
void printVS(int**, int**, int);
void userInputErase(int **, int);
void comInputErase(int **, int);
int checkBingo(int **, int);

int main(){
  int input;
  srand((unsigned int)time(NULL));
  while(1){
    switch(input = menuInput()){
      case 1 : practiceGame(); break;
      case 2 : VSGame(); break;
      case 3 : return 0;
      default : ;
    };
  }
}

int menuInput(){
  int input;
  printf("1. 연습게임(개인 연습용)\n");
  printf("2. 대전게임(컴퓨터와 대전용)\n");
  printf("3. 종료\n\n");
  printf("# 메뉴선택 : ");
  scanf("%d", &input);
  while( input<1 || input>3 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    scanf("%d", &input);
  }
  return input;
}

void practiceGame(){
  int size, **bingo;
  printf("\n연습용 빙고게임을 시작합니다.\n\n");
  printf("# 빙고판의 가로,세로 크기를 입력해주세요(양수값 입력) : ");
  scanf("%d", &size);
  bingo = makeBingo(size);
  while(1){
    printPractice(bingo, size);
    userInputErase(bingo, size);
    if(checkBingo(bingo, size) >= size){
      for(int i=0; i<size; i++){
        free(bingo[i]);
      }
      free(bingo);
      return;
    }
  }
}

void VSGame(){
  int size, **user, **computer;
  printf("\n# 빙고판의 가로,세로 크기를 입력해주세요(양수값 입력) : ");
  scanf("%d", &size);
  printf("\n사용자 빙고게임판 내용을 생성중입니다.\n");
  user = makeBingo(size);
  printf("컴퓨터 빙고게임판 내용을 생성중입니다.\n\n");
  computer = makeBingo(size);
  while(1){
    printVS(user, computer, size);
    userInputErase(user, size);
    comInputErase(computer, size);
    if(checkBingo(user, size) >= size && checkBingo(computer, size) >= size){
      printf("# 무승부!\n");
      return;
    }
    else if(checkBingo(user, size) >= size){
      printf("# 사용자 승!\n");
      return;
    }
    else if(checkBingo(computer, size) >= size){
      printf("# 컴퓨터 승\n");
      return;
    }
    else ;
  }
}

int** makeBingo(int size){
  int **bingo;
  bingo = (int**)malloc(sizeof(int*)*size);
  if(bingo == NULL){
    printf("동적할당 실패!\n");
    return NULL;
  }
  for(int i=0; i<size; i++){
    bingo[i] = (int*)malloc(sizeof(int)*size);
    if(bingo[i] == NULL){
      printf("동적할당 실패!\n");
      for(int j=0; j<i; j++)
        free(bingo[j]);
      free(bingo);
      return NULL;
    }
  }
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++){
      while(1){
        bingo[i][j] = rand()%(size*size)+1;
        if(isDuplicate(bingo, i, j, size) == FALSE)
          break;
      }
    }
  return bingo;
}

int isDuplicate(int** bingo, int i, int j, int size){
  for(int k=0; k<j; k++){
    if(bingo[i][k] == bingo[i][j])
      return TRUE;
  }
  for(int k=0; k<i; k++)
    for(int l=0; l<size; l++){
      if(bingo[k][l] == bingo[i][j])
        return TRUE;
    }
  return FALSE;
}

void printPractice(int **bingo, int size){
  printf("\n");
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      if(bingo[i][j] == 0)
        printf("    X");
      else
        printf("%5d", bingo[i][j]);
      }
    printf("\n");
  }
}

void printVS(int **user, int **computer, int size){
  printf("\n\n[user]\t");
  for(int i=0; i<size; i++)
    printf("     ");
  printf("[computer]\n");
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      if(user[i][j] == 0)
        printf("    X");
      else
        printf("%5d", user[i][j]);
      if(j == size-1){
        printf("\t");
        for(int k=0; k<size; k++){
          if(computer[i][k] == 0)
            printf("    X");
          else
            printf("    ?");
        }
      }
    }
    printf("\n");
  }
}

void userInputErase(int **bingo, int size){
  int input, duplicate = 1;
  printf("\n# 지울 숫자 입력(1~%d) : ", size*size);
  scanf("%d", &input);
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      if(bingo[i][j] == input){
        bingo[i][j] = 0;
        duplicate = 0;
        break;
      }
  while(input<1 || input>size*size || duplicate){
    printf("다시 입력하세요.\n");
    while(getchar() != '\n')
      ;
      printf("# 지울 숫자 입력(1~%d) : ", size*size);
      scanf("%d", &input);
      for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
          if(bingo[i][j] == input){
            bingo[i][j] = 0;
            duplicate = 0;
            break;
          }
  }
  return;
}

void comInputErase(int **bingo, int size){
  int input, duplicate = 1;
  input = rand()%(size*size)+1;
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      if(bingo[i][j] == input){
        bingo[i][j] = 0;
        duplicate = 0;
        break;
      }
  while(duplicate){
      input = rand()%(size*size)+1;
      for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
          if(bingo[i][j] == input){
            bingo[i][j] = 0;
            duplicate = 0;
            break;
          }
  }
  printf("컴퓨터가 선택한 숫자는 (%d)입니다.\n", input);
  return;
}

int checkBingo(int **bingo, int size){
  int cnt=0;
  for(int i=0; i<size; i++){
    for(int j=0; j<size; j++){
      if(bingo[i][j] != 0)
        break;
      if(j == size-1)
        cnt++;
      }
    for(int k=0; k<size; k++){
      if(bingo[k][i] != 0)
        break;
      if(k == size-1)
        cnt++;
    }
  }
  for(int i=0; i<size; i++){
    if(bingo[i][i] != 0)
      break;
    if(i == size-1)
      cnt++;
  }
  for(int i=0; i<size; i++){
    if(bingo[i][size-i-1] != 0)
      break;
    if(i == size-1)
      cnt++;
  }
  return cnt;
}
