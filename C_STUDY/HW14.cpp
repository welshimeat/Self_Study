#include <stdio.h>
#include <string.h>

int main(){
  char name[20];
  int len;
  printf("* 문자열 입력 : ");
  scanf("%s", name);
  len = strlen(name);
  printf("[%*.*s...]\n", len, len/2, name);
  return 0;
}
