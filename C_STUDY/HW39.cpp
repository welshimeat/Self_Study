#include <stdio.h>

int main(){
  for(int i=0; i<10; i++){
    for(int j=0; j<100; j+=10)
      printf("%-3d", i+j);
    printf("\n");
  }
  return 0;
}
