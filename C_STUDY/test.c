#include <stdio.h>

struct name{
  char abc[20];
  int size;
} name[10];
int main(){
  printf("%d %d", (name[1].abc- name[0].abc)/sizeof(struct name), 1);

}
