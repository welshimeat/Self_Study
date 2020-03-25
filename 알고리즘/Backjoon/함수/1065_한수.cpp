#include <stdio.h>

int main(){
  int num, total=0, a, b, c;
  scanf("%d", &num);
  for(int i=1; i<=num; i++){
    if(i<100)
      total++;
    else{
      a = i/100; b = i/10%10; c = i%10;
      if(a-b == b-c)
        total++;
    }
  }
  printf("%d", total);
  return 0;
}
