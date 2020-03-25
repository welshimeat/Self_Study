#include <stdio.h>
#include <string.h>
#include <ctype.h>

int inputstr(char*);
int palindrome(char*);
void printres(char*, int);

int main(){
  char str[100];
  while(inputstr(str) != 1){
    printres(str, palindrome(str));
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

int palindrome(char *str){
  int len = strlen(str);
  for(int i=0; i<len/2; i++){
    if(tolower(str[i]) != tolower(str[len-1-i]))
      return 0;
  }
  return 1;
}

void printres(char *str, int palindrome){
  if(palindrome == 1)
    printf("\"%s\" : 회문입니다!\n\n", str);
  else
    printf("\"%s\" : 회문이 아닙니다!\n\n", str);
  return;
}
