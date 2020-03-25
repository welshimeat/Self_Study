#include <stdio.h>
#include <string.h>

typedef struct Dic{
  char word[20];
  char mean[80];
  int len;
}Dic;

int inputMenu();
void inputWord(Dic *, int *);
void sortDic(Dic *, int);
void printDic(Dic *, int);
void searchWord(Dic *, int);
char* isWordinDic(Dic *, char *, int);
void deleteWord(Dic *, int *);

int main(){
  int input, size=0;
  Dic ary[10] = {0};
  while(1){
    switch(input = inputMenu()){
      case 1 : inputWord(ary, &size); break;
      case 2 : sortDic(ary, size); printDic(ary, size); break;
      case 3 : searchWord(ary, size); break;
      case 4 : deleteWord(ary, &size); break;
      case 5 : return 0;
      default : ;
    }
  }
}

int inputMenu(){
  int input;
  printf("1. 입력하기\n");
  printf("2. 출력하기\n");
  printf("3. 검색하기\n");
  printf("4. 삭제하기\n");
  printf("5. 종료\n\n");
  printf("# 메뉴선택 : ");
  scanf("%d", &input);
  while(input<1 || input>5 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("# 메뉴선택 : ");
    scanf("%d", &input);
  }
  return input;
}

void inputWord(Dic *ary, int *size){
  char temp[80];
  while(1){
    if(*size > 9)
      return;
    printf("\n# 단어를 입력하시오 : ");
    scanf("%s", temp);
    if(strcmp(temp, "end")==0){
      printf("\n\n");
      return;
    }
    else{
      strcpy(ary[*size].word, temp);
      ary[*size].len = strlen(temp);
      printf("# 뜻을 입력하시오 : ");
      getchar();
      fgets(temp, 20, stdin);
      temp[strlen(temp)] = '\0';
      if(strcmp(temp, "end")==0){
        printf("\n\n");
        (*size)++;
        return;
      }
      else{
        strcpy(ary[*size].mean, temp);
        (*size)++;
      }
    }
  }
}

void sortDic(Dic *ary, int size){
  Dic temp;
  for(int i=0; i<size-1; i++)
    for(int j=i+1; j<size; j++){
      if(strcmp(ary[i].word, ary[j].word) > 0){
        temp = ary[i];
        ary[i] = ary[j];
        ary[j] = temp;
      }
    }
}

void printDic(Dic *ary, int size){
  for(int i=0; i<size; i++){
    printf("%2d.%19s(%2d) : %s\n", i+1, ary[i].word, ary[i].len, ary[i].mean);
  }
}

void searchWord(Dic *ary, int size){
  char temp[20];
  char *address;
  while(1){
    printf("# 찾을 단어를 입력하시오 : ");
    scanf("%s", temp);
    if(strcmp(temp, "end") == 0)
      return;
    else{
      address = isWordinDic(ary, temp, size);
      if(address != NULL){
          printf("단어의 뜻 : %s\n\n", address);
      }
      else
        printf("Not found!!!\n\n");
    }
  }
}

char* isWordinDic(Dic *ary, char *temp, int size){
  for(int i=0; i<size; i++){
    if(strcmp(ary[i].word, temp) == 0)
      return ary[i].mean;
  }
  return NULL;
}

void deleteWord(Dic *ary, int *size){
  int num;
  char temp[20], input;
  char *address;
  while(1){
    printf("# 삭제할 단어를 입력하시오 : ");
    scanf("%s", temp);
    if(strcmp(temp, "end") == 0)
      return;
    address = isWordinDic(ary, temp, *size);
    if(address != NULL){
      printf("# 정말로 삭제하시겠습니까?(y/n) : ");
      scanf(" %c", &input);
      if(input == 'y'){
        num = (address - ary[0].word)/sizeof(Dic);
        for(int i=num; i<*size; i++){
          ary[i] = ary[i+1];
        }
        (*size)--;
        printf("삭제되었습니다.\n\n");
      }
      else
        printf("삭제가 취소되었습니다.\n\n");
    }
    else
      printf("Not found!!!\n\n");
  }
}
