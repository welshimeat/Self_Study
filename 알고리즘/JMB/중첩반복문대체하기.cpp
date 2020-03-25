#include <stdio.h>
#include <vector>
using namespace std;

void pick(int, vector<int>&, int);

int main(){
  int n = 4;
  vector<int> v;
  pick(n, v, 2);
}

void pick(int n, vector<int>& picked, int toPick){
  if(toPick == 0){
    for(int i=0; i<2; i++)
      printf("%d ", picked[i]);
    printf("\n");
    return;
    }
  int smallest = picked.empty() ? 0 : picked.back() + 1;
  for(int next = smallest; next < n; next++){
    picked.push_back(next);
    pick(n, picked, toPick-1);
    picked.pop_back();
  }
}
