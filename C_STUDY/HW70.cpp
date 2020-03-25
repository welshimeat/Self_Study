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
  printf("1. �Է��ϱ�\n");
  printf("2. ����ϱ�\n");
  printf("3. �˻��ϱ�\n");
  printf("4. �����ϱ�\n");
  printf("5. ����\n\n");
  printf("# �޴����� : ");
  scanf("%d", &input);
  while(input<1 || input>5 || getchar() != '\n'){
    while(getchar() != '\n')
      ;
    printf("# �޴����� : ");
    scanf("%d", &input);
  }
  return input;
}

void inputWord(Dic *ary, int *size){
  char temp[80];
  while(1){
    if(*size > 9)
      return;
    printf("\n# �ܾ �Է��Ͻÿ� : ");
    scanf("%s", temp);
    if(strcmp(temp, "end")==0){
      printf("\n\n");
      return;
    }
    else{
      strcpy(ary[*size].word, temp);
      ary[*size].len = strlen(temp);
      printf("# ���� �Է��Ͻÿ� : ");
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
    printf("# ã�� �ܾ �Է��Ͻÿ� : ");
    scanf("%s", temp);
    if(strcmp(temp, "end") == 0)
      return;
    else{
      address = isWordinDic(ary, temp, size);
      if(address != NULL){
          printf("�ܾ��� �� : %s\n\n", address);
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
    printf("# ������ �ܾ �Է��Ͻÿ� : ");
    scanf("%s", temp);
    if(strcmp(temp, "end") == 0)
      return;
    address = isWordinDic(ary, temp, *size);
    if(address != NULL){
      printf("# ������ �����Ͻðڽ��ϱ�?(y/n) : ");
      scanf(" %c", &input);
      if(input == 'y'){
        num = (address - ary[0].word)/sizeof(Dic);
        for(int i=num; i<*size; i++){
          ary[i] = ary[i+1];
        }
        (*size)--;
        printf("�����Ǿ����ϴ�.\n\n");
      }
      else
        printf("������ ��ҵǾ����ϴ�.\n\n");
    }
    else
      printf("Not found!!!\n\n");
  }
}
