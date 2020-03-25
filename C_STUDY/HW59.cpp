#include <stdio.h>

int inputnum(int *);
int countnum(int *);

int main(){
  int num[10001] = {0};
  while(inputnum(num) != 1){
    printf("  서로 다른 수의 개수 : %d\n\n", countnum(num));
  }
  return 0;
}

int inputnum(int *num){
  int input, index;
  printf("* 입력할 숫자의 개수 : ");
  scanf("%d", &input);
  if(getchar() != '\n')
    return 1;
  else{
    printf("* 숫자 입력 : ");
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
