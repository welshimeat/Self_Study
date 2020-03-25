#include <stdio.h>

int inputnum(const char*);
void myflush();

int main(){
  int num;
  num = inputnum("# 정수값을 입력하세요 : ");
  for(int i=1; i<=num; i++){
    printf("*");
    if(i%5 == 0)
      printf("\n");
  }
  return 0;
}

int inputnum(const char* msg){
  int num;
  printf(msg);
  scanf("%d", &num);
  while(getchar() != '\n'){
    myflush();
    printf(msg);
    scanf("%d", &num);
  }
  return num;
}

void myflush(){
  while(getchar() != '\n')
    ;
}
