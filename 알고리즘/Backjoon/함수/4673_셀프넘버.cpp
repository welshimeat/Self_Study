#include <stdio.h>

int main(){
  int a,b,c,d,res=0;
  for(int i=1; i<=10000; i++){
    if(i<=10){
      if(i%2==1)
        printf("%d\n", i);
    }
    else if(i<100){
      a=9; b=i/10,res=0;
      for(int j=i-a-b; j<i; j++){
        if(j+j%10+j/10 == i){
          res=1;
          break;
        }
      }
      if(res==0) printf("%d\n", i);
    }
    else if(i<1000){
      a=9; b=9; c=i/100; res=0;
      for(int j=i-a-b-c; j<i; j++){
        if(j+j%10+j/10%10+j/100 == i){
          res=1;
          break;
        }
      }
      if(res==0) printf("%d\n", i);
    }
    else{
      a=9; b=9; c=9; d=i/1000; res=0;
      for(int j=i-a-b-c-d; j<i; j++){
        if(j+j%10+j/10%10+j/100%10+j/1000 == i){
          res=1;
          break;
        }
      }
      if(res==0) printf("%d\n", i);
    }
  }
  return 0;
}
