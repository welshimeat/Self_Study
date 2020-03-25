#include <stdio.h>

int main(){
  int a, b;
  printf("# 두개의 정수를 입력하세요 : ");
  scanf("%d %d", &a, &b);
  while(getchar() == '\n'){
    if(a>=b)
      printf("%d - %d = %d\n", a, b, a-b);
    else
      printf("%d - %d = %d\n", b, a, b-a);
    printf("# 두개의 정수를 입력하세요 : ");
    scanf("%d %d", &a, &b);
  }
  return 0;
}
