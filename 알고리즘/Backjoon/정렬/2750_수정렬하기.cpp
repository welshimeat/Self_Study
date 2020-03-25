#include <stdio.h>
#include <stdlib.h>

int main(){
  int num, *arr, temp;
  scanf("%d", &num);
  arr = (int*)malloc(num * sizeof(int));
  for(int i=0; i<num; i++)
    scanf("%d", arr+i);

  for(int i=0; i<num-1; i++)
    for(int j=i+1; j<num; j++){
      if(arr[i] > arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

  for(int i=0; i<num; i++)
    printf("%d\n", arr[i]);
  return 0;
}
