#include <stdio.h>

int inputdata(int*);
void sort(int*, int);
void printres(int*, int);

int main(){
  int data[101], index;
  for(int i=1; i<=3; i++){
    printf("%d차 데이터 입력 : ", i);
    index = inputdata(data);
    printf("# 소트 전 데이터 : ");
    printres(data, index);
    sort(data, index);
    printf("# 소트 후 데이터 : ");
    printres(data, index);
  }
  return 0;
}

int inputdata(int *data){
  int i=0;
  while(1){
    scanf("%d", &data[i]);
    if(data[i] == 0)
      break;
    else i++;
  }
  return i;
}

void sort(int *data, int index){
  int temp;
  for(int i=0; i<index-1; i++)
    for(int j=i+1; j<index; j++)
      if(data[i]>data[j]){
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
}

void printres(int *data, int index){
  for(int i=0; i<index; i++)
    printf("%d ", data[i]);
  printf("\n");
}
