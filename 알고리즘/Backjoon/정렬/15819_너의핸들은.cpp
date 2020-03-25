#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
  int num, index;
  string handle[100], temp;

  scanf("%d %d", &num, &index);
  for(int i=0; i<num; i++)
    cin >> handle[i];
  for(int i=0; i<num-1; i++)
    for(int j=i+1; j<num; j++){
      if(handle[i] > handle[j]){
        temp = handle[i];
        handle[i] = handle[j];
        handle[j] = temp;
      }
    }
  cout << handle[index-1] << endl;
}
