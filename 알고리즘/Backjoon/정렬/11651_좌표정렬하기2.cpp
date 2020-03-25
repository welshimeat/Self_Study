#include <iostream>
#include <cstdlib>
using namespace std;
int N;
typedef struct pos{
  int x;
  int y;
} pos;
pos arr[100000];
int compare(const void*, const void*);

int main(){
  //pos temp;
  scanf("%d", &N);
  for(int i=0; i<N; i++)
    scanf("%d %d", &arr[i].x, &arr[i].y);
  qsort(arr, N, sizeof(pos), compare);
  for(int i=0; i<N; i++)
    printf("%d %d\n", arr[i].x, arr[i].y);
}

int compare(const void* p1, const void* p2){
  if(((pos*)p1)->y > ((pos*)p2)->y || (((pos*)p1)->y == ((pos*)p2)->y && ((pos*)p1)->x > ((pos*)p2)->x))
    return 1;
  else return -1;
}
