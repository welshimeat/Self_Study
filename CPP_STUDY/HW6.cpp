#include <iostream>
#include <string.h>
using namespace std;

int my_strlen(char *, char = '\0');

int main(){
  char str[60], ch;
  cout << "문자열 입력 : ";
  cin.getline(str, sizeof(str));
  cout << "문자열의 길이 : " << my_strlen(str) << "\n문자 입력 : ";
  cin >> ch;
  cout << ch << " 이전 까지의 길이 : " << my_strlen(str, ch);
}

int my_strlen(char *str, char ch){
  int cnt=0;
  while(*str != '\0' && *str != ch){
    str++; cnt++;
  }
  return cnt;
}
