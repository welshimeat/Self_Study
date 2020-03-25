#include <stdio.h>
#include <stdlib.h>

void solve(int);
int promising(int);
int sudoku[9][9], num;
struct location{
  int x;
  int y;
  int* value;
};
location location[100];


int main(){
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++){
      scanf("%d", &sudoku[i][j]);
      if(sudoku[i][j] == 0){
        location[num].x = i;
        location[num].y = j;
        location[num].value = &sudoku[i][j];
        num++;
      }
    }
  printf("\n");
  solve(-1);
}

void solve(int i){
  if(i == -1 || promising(i)){
    if(i == num-1){
      for(int j=0; j<9; j++){
        for(int k=0; k<9; k++){
          printf("%d ", sudoku[j][k]);
        }
        printf("\n");
      }
      exit(0);
    }
    else{
      for(int l=1; l<=9; l++){
        *location[i+1].value = l;
        solve(i+1);
        *location[i+1].value = 0;
      }
    }
  }
}

int promising(int i){
  int Switch=1, x = location[i].x-location[i].x%3, y = location[i].y-location[i].y%3;
  for(int k=0; k<=8; k++){
    if((k != location[i].y && sudoku[location[i].x][k] == *location[i].value) || (k != location[i].x && sudoku[k][location[i].y] == *location[i].value)){
       Switch = 0;
       return Switch;
     }
   }
  for(int m=x; m<x+3; m++)
    for(int n=y; n<y+3; n++){
      if(m == location[i].x && n == location[i].y)
        continue;
      else{
        if(sudoku[m][n] == *location[i].value){
          return Switch;
        }
      }
    }
  return Switch;
}
