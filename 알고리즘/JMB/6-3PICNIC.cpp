#include <iostream>

int C, n, m, isfriend[10][10], ans[50];
int taken[10];
int countParings(int*);

int main(){
  int f1, f2;
  scanf("%d", &C);

  for(int i=0; i<C; i++){
    scanf("%d %d", &n, &m);
    for(int j=0; j<m; j++){
      scanf("%d %d", &f1, &f2);
      isfriend[f1][f2] = 1;
      isfriend[f2][f1] = 1;
    }
    ans[i] = countParings(taken);
    for(int i=0; i<n; i++){
      taken[i] = 0;
      for(int j=0; j<n; j++){
        isfriend[i][j] = 0;
      }
    }
  }
  for(int i=0; i<C; i++)
    printf("%d\n", ans[i]);
  return 0;
}

int countParings(int *taken){
  int firstFree = -1;
  for(int i=0; i<n; i++){
    if(taken[i] == 0){
      firstFree = i;
      break;
    }
  }
  if(firstFree == -1)
    return 1;
  int ret = 0;
  for(int pairWith=firstFree+1; pairWith<n; pairWith++)
      if(taken[pairWith]==0 && isfriend[firstFree][pairWith] == 1){
        taken[firstFree] = taken[pairWith] = 1;
        ret += countParings(taken);
        taken[firstFree] = taken[pairWith] = 0;
      }
  return ret;
}
