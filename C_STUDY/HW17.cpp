#include <stdio.h>
#include <string.h>

int main(){
  char name[20], gender;
  int len;
  double height;
  printf("# ���� �Է� : ");
  fgets(name, sizeof(name), stdin);
  len = strlen(name);
  name[len-1] = '\0';
  printf("# Ű �Է�(cm����) : ");
  scanf("%lf", &height);
  printf("# �����Է�(M/F) : ");
  scanf(" %c", &gender);
  if(gender == 'M')
    printf("%s���� Ű��  %.2lfcm�̰� �����Դϴ�.\n", name, height);
  else if(gender == 'F')
    printf("%s���� Ű��  %.2lfcm�̰� �����Դϴ�.\n", name, height);
  return 0;
}
