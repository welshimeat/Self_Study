#include <stdio.h>

int inputweight();
void myflush();

int main(){
  int weight, i=0;
  while(i < 10){
    weight = inputweight();
    if(weight < 150){
    printf("* ���߸��� ������ �峭���� ���ÿ�~ ^^\n");
    }
    else if(weight > 500){
      printf("* Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
    }
    else{
      i++;
      printf("* ���� �ް��� �� : %d\n", i);
    }
  }
  printf("\n*** �ް� ������ �������ϴ�.\n");
}

int inputweight(){
  int weight;
  printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
  scanf("%d", &weight);
  while(getchar() != '\n'){
    myflush();
    printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
    scanf("%d", &weight);
  }
  return weight;
}

void myflush(){
  while(getchar() != '\n')
  ;
}
