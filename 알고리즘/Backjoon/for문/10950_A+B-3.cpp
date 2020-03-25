#include <stdio.h>

int main(){
  int num;
  scanf("%d", &num);
  int a[num], b[num];
  for(int i=0; i<num; i++)
    scanf("%d %d", &a[i], &b[i]);
  for(int i=0; i<num; i++)
    printf("%d\n", a[i]+b[i]);
  return 0;
}
