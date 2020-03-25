#include <stdio.h>

int inputweight();
void myflush();

int main(){
  int weight, i=0;
  while(i < 10){
    weight = inputweight();
    if(weight < 150){
    printf("* 메추리알 가지고 장난하지 마시오~ ^^\n");
    }
    else if(weight > 500){
      printf("* 타조알 가지고 장난하지 마시오~ ^^\n");
    }
    else{
      i++;
      printf("* 현재 달걀의 수 : %d\n", i);
    }
  }
  printf("\n*** 달걀 포장이 끝났습니다.\n");
}

int inputweight(){
  int weight;
  printf("# 계란의 무게를 입력하세요(단위 : g) : ");
  scanf("%d", &weight);
  while(getchar() != '\n'){
    myflush();
    printf("# 계란의 무게를 입력하세요(단위 : g) : ");
    scanf("%d", &weight);
  }
  return weight;
}

void myflush(){
  while(getchar() != '\n')
  ;
}
