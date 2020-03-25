#include <stdio.h>
#include <string.h>

void inputstr(char (*)[20]);
void sortstr(char (*)[20]);
void printstr(char (*)[20]);

int main(){
  char str[5][20];
  inputstr(str);
  sortstr(str);
  printstr(str);
  return 0;
}

void inputstr(char (*str)[20]){
  for(int i=0; i<5; i++){
    printf("# %d번 문자열을 입력하시오 : ", i+1);
    scanf("%s", str[i]);
  }
  return;
}

void sortstr(char (*str)[20]){
  char temp[20];
  for(int i=0; i<4; i++)
    for(int j=i+1; j<5; j++){
      if(strcmp(str[i], str[j]) == 1){
        strcpy(temp, str[i]);
        strcpy(str[i], str[j]);
        strcpy(str[j], temp);
      }
    }
}

void printstr(char (*str)[20]){
  for(int i=0; i<5; i++){
    printf("\nstr[%d] = %s   %c  %c", i, str[i], str[i][0], str[i][strlen(str[i])-1]);
  }
}
