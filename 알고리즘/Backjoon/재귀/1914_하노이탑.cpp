#include <stdio.h>
#include <math.h>

void HanoiTower(int ,int, int, int);

int main(){
  int N;
  long double cnt=0;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    cnt += pow(2, i);
  printf("%lf\n", cnt);
  if(N<20)
    HanoiTower(N, 1, 2, 3);
  return 0;
}

void HanoiTower(int num, int from, int by, int to){
  if(num==1){
    printf("%d %d\n", from, to);
  }
  else{
    HanoiTower(num-1, from, to, by);
    printf("%d %d\n", from, to);
    HanoiTower(num-1, by, from, to);
  }
}
