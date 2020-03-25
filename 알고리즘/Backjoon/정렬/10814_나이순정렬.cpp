#include <iostream>
#include <cstring>
#include <cstdlib>

typedef struct person{
  int num;
  int age;
  char name[101];
} person;
int compare(const void*, const void*);

int main(){
  int num;
  char temp[101];
  scanf("%d", &num);
  person judge[num];
  for(int i=0; i<num; i++){
    judge[i].num = i;
    scanf("%d %s", &judge[i].age, temp);
    strcpy(judge[i].name, temp);
  }
  qsort(judge, num, sizeof(person), compare);
  for(int i=0; i<num; i++){
    printf("%d %s\n", judge[i].age, judge[i].name);
  }
  return 0;
}

int compare(const void *p1, const void *p2){
  if(((person*)p1)->age > ((person*)p2)->age)
    return 1;
  else if((((person*)p1)->age == ((person*)p2)->age) && (((person*)p1)->num > ((person*)p2)->num))
    return 1;
  else return -1;
}
