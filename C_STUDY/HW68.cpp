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
  printf("1. ��������(���� ������)\n");
  printf("2. ��������(��ǻ�Ϳ� ������)\n");
  printf("3. ����\n\n");
  printf("# �޴����� : ");
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
  printf("\n������ ��������� �����մϴ�.\n\n");
  printf("# �������� ����,���� ũ�⸦ �Է����ּ���(����� �Է�) : ");
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
  printf("\n# �������� ����,���� ũ�⸦ �Է����ּ���(����� �Է�) : ");
  scanf("%d", &size);
  printf("\n����� ��������� ������ �������Դϴ�.\n");
  user = makeBingo(size);
  printf("��ǻ�� ��������� ������ �������Դϴ�.\n\n");
  computer = makeBingo(size);
  while(1){
    printVS(user, computer, size);
    userInputErase(user, size);
    comInputErase(computer, size);
    if(checkBingo(user, size) >= size && checkBingo(computer, size) >= size){
      printf("# ���º�!\n");
      return;
    }
    else if(checkBingo(user, size) >= size){
      printf("# ����� ��!\n");
      return;
    }
    else if(checkBingo(computer, size) >= size){
      printf("# ��ǻ�� ��\n");
      return;
    }
    else ;
  }
}

int** makeBingo(int size){
  int **bingo;
  bingo = (int**)malloc(sizeof(int*)*size);
  if(bingo == NULL){
    printf("�����Ҵ� ����!\n");
    return NULL;
  }
  for(int i=0; i<size; i++){
    bingo[i] = (int*)malloc(sizeof(int)*size);
    if(bingo[i] == NULL){
      printf("�����Ҵ� ����!\n");
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
  printf("\n# ���� ���� �Է�(1~%d) : ", size*size);
  scanf("%d", &input);
  for(int i=0; i<size; i++)
    for(int j=0; j<size; j++)
      if(bingo[i][j] == input){
        bingo[i][j] = 0;
        duplicate = 0;
        break;
      }
  while(input<1 || input>size*size || duplicate){
    printf("�ٽ� �Է��ϼ���.\n");
    while(getchar() != '\n')
      ;
      printf("# ���� ���� �Է�(1~%d) : ", size*size);
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
  printf("��ǻ�Ͱ� ������ ���ڴ� (%d)�Դϴ�.\n", input);
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
