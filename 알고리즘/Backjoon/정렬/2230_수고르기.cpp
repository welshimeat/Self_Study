#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int compare(const void *, const void *);

int main(){
  int N, M, gap=2000000000, i=0, j=0;
  scanf("%d %d", &N, &M);
  int arr[N];
  for(int i=0; i<N; i++)
    scanf("%d", &arr[i]);
  qsort(arr, N, sizeof(int), compare);
  while(j<N){
    if(arr[j] - arr[i] < M)
      j++;
    else
      gap = min(gap, arr[j] - arr[i++]);
  }
  printf("%d\n", gap);
}

int compare(const void *p1, const void *p2){
  if(*(int*)p1 > *(int*)p2)
    return 1;
  else return -1;
}
