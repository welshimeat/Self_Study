#include <stdio.h>
#include <stdlib.h>

int compare(const void* p, const void* q);
struct maxcount{
  int num = 0;
  int count = 0;
};


int main(){
  int num, *arr, tempcount, tempnum;
  double avg=0;
  scanf("%d", &num);
  struct maxcount maxcount[num];
  arr = (int*)malloc(num * sizeof(int));
  for(int i=0; i<num; i++){
    scanf("%d", arr+i);
    avg += arr[i];
    maxcount[i].num = arr[i];
    maxcount[i].count++;
  }

  for(int i=0; i<num-1; i++)
    for(int j=i+1; j<num; j++){
      if(maxcount[i].num == maxcount[j].num){
          maxcount[j].num = 4001;
          maxcount[j].count = -1;
          maxcount[i].count++;
      }
      else if(maxcount[i].count < maxcount[j].count){
        tempcount = maxcount[i].count;
        tempnum = maxcount[i].num;
        maxcount[i].count = maxcount[j].count;
        maxcount[i].num = maxcount[j].num;
        maxcount[j].count = tempcount;
        maxcount[j].num = tempnum;
      }
      else if(maxcount[i].count >0 && maxcount[i].count == maxcount[j].count){
        if(maxcount[i].num > maxcount[j].num){
          tempnum = maxcount[i].num;
          maxcount[i].num = maxcount[j].num;
          maxcount[j].num = tempnum;
        }
      }
    }

  qsort(arr, num, sizeof(int), compare);
  printf("\n%.0lf\n", avg/num);
  printf("%d\n", arr[num/2]);
  if(num==1)   printf("%d\n", maxcount[0].num);
  else  printf("%d\n", maxcount[1].num);
  printf("%d\n", arr[num-1]-arr[0]);
  return 0;
}

int compare(const void* p, const void* q){
  if(*(int*)p > *(int*)q)
    return 1;
  else if(*(int*)p < *(int*)q)
    return -1;
  else return 0;
}
