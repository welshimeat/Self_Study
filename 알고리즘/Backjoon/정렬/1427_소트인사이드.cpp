#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b){
  return a>b;
}

int main(){
  int num, inside[10], i=0;
  scanf("%d", &num);
  while(num != 0){
    inside[i++] = num%10;
    num /= 10;
  }
  sort(inside, inside+i, desc);
  for(int j=0; j<i; j++)
    printf("%d", inside[j]);
}
