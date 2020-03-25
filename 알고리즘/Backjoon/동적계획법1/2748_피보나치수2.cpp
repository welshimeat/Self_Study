#include <stdio.h>

int main(){
  int num;
  unsigned long long fibonacci[100] = {0};
  scanf("%d", &num);
  fibonacci[1] = 1;
  for(int i=2; i<=num; i++)
    fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
  printf("%llu", fibonacci[num]);
  return 0;
}
