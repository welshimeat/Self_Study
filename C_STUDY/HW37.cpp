#include <stdio.h>

int inputnum();

int main(){
  int day, total=0, repeat=0, i=1;
  day = inputnum();
  while(1){
    for(int j=1; j<=i; j++){
      repeat++;
      if(repeat > day)
        break;
      total += i;
    }
    if(repeat > day)
      break;
    i++;
  }

  printf("근무일 : %d 일 / 총 금화 수 : %d개\n", day, total);
  return 0;
}

int inputnum(){
  int num;
  printf("* 기사의 근무일수를 입력하시오 : ");
  scanf("%d", &num);
  while(getchar() != '\n'){
    while(getchar() != '\n')
      ;
      printf("* 기사의 근무일수를 입력하시오 : ");
    scanf("%d", &num);
  }
  return num;
}
