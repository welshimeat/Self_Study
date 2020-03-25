#include <iostream>
#include <cstring>
#include <cstdlib>

int compare(const void*, const void*);

int main(){
  int length;
  char arr[1001];
  scanf("%s", arr);

  length = strlen(arr);
  char tail[length][1001];
  for(int i=0; i<length; i++){
    strcpy(tail[i], arr+i);
  }

  qsort(tail, length, sizeof(tail[0]), compare);
  for(int i=0; i<length; i++){
    printf("%s\n", tail[i]);
  }
}

int compare(const void *p1, const void *p2){
  return (strcmp((char*)p1, (char*)p2));
}
