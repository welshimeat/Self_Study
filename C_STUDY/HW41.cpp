#include <stdio.h>

int main(){
  char ch;
  while(1){
    printf("* 영문자 대문자 입력('A'~ 'Z') : ");
    scanf(" %c", &ch);
    if(ch>'Z' || ch<'A')
      return 0;
    for(int i=0; i<=ch-'A'; i++){
      for(int j=0; j<=i; j++)
        printf("%c", ch-j);
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
