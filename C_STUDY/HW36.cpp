#include <stdio.h>

int inputnum();
int fibonacci(int);

int main(){
  int num, sum=0;
  num = inputnum();
  for(int i=1; i<=num; i++){
    if(i<num){
      printf("%d + ", fibonacci(i));
      sum += fibonacci(i);
    }
    else printf("%d = %d\n", fibonacci(i), sum+=fibonacci(i));
  }
  return 0;
}

int inputnum(){
  int num;
  printf("�Ǻ���ġ ������ �׼��� �Է��Ͻÿ� : ");
  scanf("%d", &num);
  while(getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("�Ǻ���ġ ������ �׼��� �Է��Ͻÿ� : ");
    scanf("%d", &num);
  }
  return num;
}

int fibonacci(int num){
  if(num==1) return 1;
  else if(num==2) return 1;
  else return fibonacci(num-1) + fibonacci(num-2);
}
