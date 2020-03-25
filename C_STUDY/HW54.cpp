#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int inputstr(char*);
int calculatenum(char*);

int main(){
  char str[100];
  while(inputstr(str) != 1){
    printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n\n", str, calculatenum(str));
  }
  return 0;
}

int inputstr(char *str){
  printf("# 단어 입력 : ");
  scanf("%s", str);
  if(strcmp(str, "end")==0)
    return 1;
  return 0;
}

int calculatenum(char *str){
  int len = strlen(str), total=0;
  for(int i=0; i<len; i++)
    if(str[i]>='0' && str[i]<='9'){
      total += atoi(str+i);
      i++;
      while(str[i]>='0' && str[i]<='9')
        i++;
    }
  return total;
}
