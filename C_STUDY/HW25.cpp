#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inputnum(int, int);
void printmsg(int, int);
void myflush();

int main(){
  srand((unsigned int)time(NULL));
  int num, res, i=0, min=0, max=101;
  res = rand() % 100 + 1;
  while(1){
    num = inputnum(min, max);
    i++;
    if(num == res) break;
    else if(res>num){
      min = num;
      printmsg(min, max);
    }
    else{
      max = num;
      printmsg(min, max);
    }
  }
  printf("���~ �¾Ҵ�~~~ ��ī��ī~~ %d ��° ���� ���߼̽��ϴ�.", i);
  return 0;
}

int inputnum(int min, int max){
  int num;
  printf("# ���ڸ� �Է��Ͻÿ� : ");
  scanf("%d", &num);
  while(num<=min || num>=max || getchar() != '\n'){
    myflush();
    printf("# ���ڸ� �Է��Ͻÿ� : ");
    scanf("%d", &num);
  }
  return num;
}

void printmsg(int min, int max){
    printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", min, max);
}

void myflush(){
  while(getchar() != '\n')
    ;
}
