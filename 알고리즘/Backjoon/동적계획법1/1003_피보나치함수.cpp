#include <stdio.h>

int main(){
  int cero[41] = {1,0}, uno[41] = {0, 1}, num;
  scanf("%d", &num);
  int test[num];
  for(int i=0; i<num; i++)
    scanf("%d", &test[i]);
  for(int j=0; j<num; j++){
    for(int i=2; i<=test[j]; i++){
      cero[i] = cero[i-1] + cero[i-2];
      uno[i] = uno[i-1] + uno[i-2];
    }
    printf("%d %d\n", cero[test[j]], uno[test[j]]);
  }
  return 0;
}
