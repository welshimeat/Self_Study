#include <stdio.h>

int inputnum(const char*);
void myflush();

int main(){
  int num;
  num = inputnum("# �������� �Է��ϼ��� : ");
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
