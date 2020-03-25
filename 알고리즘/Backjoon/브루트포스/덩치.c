#include <stdio.h>

struct person{
  int x;
  int y;
  int rank;
};

int main(){
  struct person person[51];
  int num;
  scanf("%d",&num);
  for(int i=1; i<=num; i++){
    scanf("%d %d",&(person[i].x), &(person[i].y));
    person[i].rank = 1;
  }

  for(int i=1; i<=num; i++)
    for(int j=1; j<=num; j++)
      if(person[i].x < person[j].x && person[i].y < person[j].y)
        person[i].rank++;

  for(int i=1; i<=num; i++)
    printf("%d ",person[i].rank);
}
