#include <iostream>
#include <vector>

int hasWord(int, int, char*);

char BOGGLE[5][5];
const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 1, 0, 1, -1, 0, 1, -1};

int main(){
  char word[10];
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
      scanf(" %c", &BOGGLE[i][j]);
  scanf("%s", word);
  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++){
      if(hasWord(i, j, word) == 1){
        printf("1\n");
        return 0;
      }
    }
  printf("0\n");
  return 0;
}

int hasWord(int x, int y, char *word){
  if(word[0] == '\0')
    return 1;
  else if(x<0 || x>4 || y<0 || y>4)
    return 0;
  else if(word[0] != BOGGLE[x][y])
    return 0;
  else{
    for(int i=0; i<8; i++){
      if(hasWord(x+dx[i], y+dy[i], word+1) == 1)
        return 1;
    }
    return 0;
  }
}
