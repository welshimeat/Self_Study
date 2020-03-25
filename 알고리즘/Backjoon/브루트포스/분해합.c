#include <stdio.h>

int main(){
  int N, total=0, num=0, min=1000000;
  scanf("%d", &N);
  int temp1 = N, temp2;

  while(temp1!=0){
    temp1 /= 10;
    num++;
  }

  for(temp1=N-1; temp1>=N-num*9; temp1--){
    temp2 = temp1;
    for(int i=1; i<=num; i++){
      total += temp2%10;
      temp2 /= 10;
      if(i==num){
        total += temp1;
        if(total==N && temp1<=min)
          min = temp1;
        else
          total = 0;
      }
    }
  }
  if(min == 1000000)
    min = 0;
  printf("%d", min);
}
