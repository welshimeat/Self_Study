#include <stdio.h>

void swap(int*, int);

int main(){
  int ary[] = {1,2,3,4,5};
  int len = sizeof(ary)/sizeof(ary[0]);

  printf("처음 배열에 저장된 값 :");
  for(int i=0; i<len; i++)
    printf("%4d", ary[i]);
  swap(ary, len);
  printf("\n바뀐 배열에 저장된 값 :");
  for(int i=0; i<len; i++)
    printf("%4d", ary[i]);
  return 0;
}

void swap(int *ary, int len){
  int temp;
  for(int i=0; i<=len/2-1; i++){
    temp = ary[i];
    ary[i] = ary[len-1-i];
    ary[len-1-i] = temp;
  }
  return;
}
