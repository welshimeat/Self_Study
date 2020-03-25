#include <stdio.h>
#include <string.h>

int inputstr(char*, char*);
int strcheck(char*, char);

int main(){
  char str[100], ch;
  int res;
  while(inputstr(str, &ch) == 0){
    if((res = strcheck(str, ch)) != -1)
      printf("\"%s\"문자열 안에 '%c'문자는 %d번 위치에 존재합니다.\n\n", str, ch, res);
    else  printf("\"%s\"문자열 안에 '%c'문자는 존재하지 않습니다.\n\n", str, ch);
  }
  return 0;
}

 int inputstr(char* str, char* ch){
  printf("# 문자열을 입력하시오 : ");
  scanf("%s", str);
  if(strcmp(str, "end") == 0)
    return 1;
  printf("# 문자를 입력하시오 : ");
  scanf(" %c", ch);
  return 0;
}

int strcheck(char* str, char ch){
  int len = strlen(str);
  for(int i=0; i<len; i++){
    if(str[i] == ch)
      return i;
    else ;
  }
  return -1;
}
