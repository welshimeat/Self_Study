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
  printf("# 시작 값을 입력하시오 : ");
  scanf("%d", start);
  while(*start<0 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("# 시작 값을 입력하시오 : ");
    scanf("%d", start);
  }
  printf("# 끝 값을 입력하시오 : ");
  scanf("%d", end);
  while(*end<0 || *end<=*start || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("# 끝 값을 입력하시오 : ");
    scanf("%d", end);
  }
  return;
}

char inputEO(int start, int end){
  char input;
  printf("* %d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", start, end);
  scanf(" %c", &input);
  while(input != 'e' && input != 'o'){
    while(getchar() != '\n')
      ;
    printf("* %d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", start, end);
    scanf(" %c", &input);
  }
  return input;
}

void printRes(int start, int end){
  int total = 0;
  switch(inputEO(start, end)){
    case 'e' : printf("  %d~%d 까지의 짝수(", start, end);
               for(int i=start; i<=end; i++)
                 if(i%2==0){
                   printf("%d ", i);
                   total += i;
                 }
               printf("\b)의 합은 %d입니다.\n", total);
               break;
    case 'o' : printf("  %d~%d 까지의 홀수(", start, end);
               for(int i=start; i<=end; i++)
                 if(i%2!=0){
                   printf("%d ", i);
                   total += i;
                 }
               printf("\b)의 합은 %d입니다.\n", total);
               break;
    default : ;
  }
  return;
}
