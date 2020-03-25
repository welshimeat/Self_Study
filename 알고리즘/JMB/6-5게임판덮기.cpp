#include <stdio.h>

int shape[20];
char board[20][20];
int whitecnt;
int C, H, W;
int shape_x[] = {1, 1, -1, -1};
int shape_y[] = {1, -1, -1, 1};
int countComplete(int, int);

int main(){
  scanf("%d", &C);
  for(int i=0; i<C; i++){
    scanf("%d %d", &H, &W);
    for(int j=0; j<H; j++){
      for(int k=0; k<W; k++){
        scanf(" %c", &board[j][k]);
        if(board[j][k] == '.')
          whitecnt++;
      }
    }
    printf("%d", countComplete(0,1));
  }
}

int countComplete(int x, int y){
  int res=0;
  if(x == W-1 && y == H-1)
    return 1;
  else if(whitecnt%3 !=0)
    return 12;
  else if(x >= W || y>= H)
    return 103;
  else if(board[x][y] == '#')
    return 1004;

  for(int i=0; i<4; i++){
    if(board[x + shape_x[i]][y] == '#' || board[x][y + shape_y[i]] == '#')
      continue;
    else{
      board[x + shape_x[i]][y] = '#';
      board[x][y + shape_y[i]] = '#';
      if(x==W-1){
        res +=countComplete(0, y+1);
      }
      else res+=countComplete(x+1, y);
      board[x + shape_x[i]][y] = '.';
      board[x][y + shape_y[i]] = '.';
    }
  }
  return res;
}
