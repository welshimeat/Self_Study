#include <stdio.h>
#include <stdlib.h>

int num, add, sub, mult, divide, *arr, max=-1000000000, min=1000000000, symbol[11];
void solve(int);
int promising(int);
int calculate();

int main(){
  scanf("%d", &num);
  arr = (int*)malloc(num * sizeof(int));
  for(int i=0; i<num; i++)
    scanf("%d", &arr[i]);
  scanf("%d %d %d %d", &add, &sub, &mult, &divide);
  solve(0);
  printf("%d\n%d", max, min);
  return 0;
}

void solve(int i){
  if(promising(i)){
    if(i==num-1){
      int total = calculate();
      if(total>max)
        max = total;
      if(total<=min){
        min = total;
      }
    }
    else{
      for(int j=1; j<=4; j++){
        symbol[i+1] = j;
        solve(i+1);
      }
    }
  }
}

int promising(int i){
  int k=1, cnt=0;
  while(k<=i){
    if(symbol[k] == symbol[i])
      cnt++;
    k++;
  }
  switch(symbol[i]){
    case 1 : if(cnt>add) return 0; break;
    case 2 : if(cnt>sub) return 0; break;
    case 3 : if(cnt>mult) return 0; break;
    case 4 : if(cnt>divide) return 0;
  }
  return 1;
}

int calculate(){
  int total = arr[0];
  for(int k=1; k<num; k++){
    switch(symbol[k]){
      case 1 : total += arr[k]; break;
      case 2 : total -= arr[k]; break;
      case 3 : total *= arr[k]; break;
      case 4 : total /= arr[k];
    }
  }
  return total;
}
