#include <stdio.h>
#include <string.h>

int inputstr(char*, char*);
int strcheck(char*, char);

int main(){
  char str[100], ch;
  int res;
  while(inputstr(str, &ch) == 0){
    if((res = strcheck(str, ch)) != -1)
      printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� %d�� ��ġ�� �����մϴ�.\n\n", str, ch, res);
    else  printf("\"%s\"���ڿ� �ȿ� '%c'���ڴ� �������� �ʽ��ϴ�.\n\n", str, ch);
  }
  return 0;
}

 int inputstr(char* str, char* ch){
  printf("# ���ڿ��� �Է��Ͻÿ� : ");
  scanf("%s", str);
  if(strcmp(str, "end") == 0)
    return 1;
  printf("# ���ڸ� �Է��Ͻÿ� : ");
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
