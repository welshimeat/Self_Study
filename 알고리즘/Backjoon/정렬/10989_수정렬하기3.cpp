#include <stdio.h>
#include <stdlib.h>


int main(){
  int num, input, arr[10000] = {0};
  scanf("%d", &num);
  for(int i=0; i<num; i++){
    scanf("%d", &input);
    arr[input-1]++;
  }

  for(int i=0; i<10000; i++)
    for(int j=0; j<arr[i]; j++)
      printf("%d\n", i+1);
  return 0;
}
