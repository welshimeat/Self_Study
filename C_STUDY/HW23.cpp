#include <stdio.h>

int main(){
  int a, b;
  printf("# �ΰ��� ������ �Է��ϼ��� : ");
  scanf("%d %d", &a, &b);
  while(getchar() == '\n'){
    if(a>=b)
      printf("%d - %d = %d\n", a, b, a-b);
    else
      printf("%d - %d = %d\n", b, a, b-a);
    printf("# �ΰ��� ������ �Է��ϼ��� : ");
    scanf("%d %d", &a, &b);
  }
  return 0;
}
