#include <stdio.h>
#include <stdlib.h>

int compare(const void* p, const void* q);

int main(){
  int num, *arr;
  scanf("%d", &num);
  arr = (int*)malloc(num * sizeof(int));
  for(int i=0; i<num; i++)
    scanf("%d", arr+i);

  qsort(arr, num, sizeof(int), compare);

  for(int i=0; i<num; i++)
    printf("%d\n", arr[i]);
  return 0;
}

int compare(const void* p, const void* q){
  if(*(int*)p > *(int*)q)
    return 1;
  else if(*(int*)p < *(int*)q)
    return -1;
  else return 0;
}
