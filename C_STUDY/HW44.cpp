#include <stdio.h>

void inputNum(int*, int*);
char inputEO(int, int);
void printRes(int , int);

int main(){
  int start, end;
  inputNum(&start, &end);
  printRes(start, end);
  return 0;
}

void inputNum(int *start, int *end){
  printf("# ���� ���� �Է��Ͻÿ� : ");
  scanf("%d", start);
  while(*start<0 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("# ���� ���� �Է��Ͻÿ� : ");
    scanf("%d", start);
  }
  printf("# �� ���� �Է��Ͻÿ� : ");
  scanf("%d", end);
  while(*end<0 || *end<=*start || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("# �� ���� �Է��Ͻÿ� : ");
    scanf("%d", end);
  }
  return;
}

char inputEO(int start, int end){
  char input;
  printf("* %d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", start, end);
  scanf(" %c", &input);
  while(input != 'e' && input != 'o'){
    while(getchar() != '\n')
      ;
    printf("* %d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦��:e/Ȧ��:o) : ", start, end);
    scanf(" %c", &input);
  }
  return input;
}

void printRes(int start, int end){
  int total = 0;
  switch(inputEO(start, end)){
    case 'e' : printf("  %d~%d ������ ¦��(", start, end);
               for(int i=start; i<=end; i++)
                 if(i%2==0){
                   printf("%d ", i);
                   total += i;
                 }
               printf("\b)�� ���� %d�Դϴ�.\n", total);
               break;
    case 'o' : printf("  %d~%d ������ Ȧ��(", start, end);
               for(int i=start; i<=end; i++)
                 if(i%2!=0){
                   printf("%d ", i);
                   total += i;
                 }
               printf("\b)�� ���� %d�Դϴ�.\n", total);
               break;
    default : ;
  }
  return;
}
