#include <stdio.h>

int inputnum(int *);
int countnum(int *);

int main(){
  int num[10001] = {0};
  while(inputnum(num) != 1){
    printf("  ���� �ٸ� ���� ���� : %d\n\n", countnum(num));
  }
  return 0;
}

int inputnum(int *num){
  int input, index;
  printf("* �Է��� ������ ���� : ");
  scanf("%d", &input);
  if(getchar() != '\n')
    return 1;
  else{
    printf("* ���� �Է� : ");
    for(int i=0; i<input; i++){
      scanf("%d", &index);
      num[index]++;
    }
  }
  return 0;
}

int countnum(int *num){
  int cnt = 0;
  for(int i=1; i<=10000; i++){
    if(num[i]>0){
      num[i] = 0;
      cnt++;
    }
  }
  return cnt;
}
