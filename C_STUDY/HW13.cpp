#include <stdio.h>
#include <string.h>

int main(){
  char last[20], first[20];
  int len1, len2;
  printf("#���� �Է��Ͻÿ� : ");
  scanf("%s", last);
  len1 = strlen(last);
  printf("#�̸��� �Է��Ͻÿ� : ");
  scanf("%s", first);
  len2 = strlen(first);
  printf("%s %s\n", last, first);
  printf("%*d %*d", len1, len1, len2, len2);
  return 0;
}
