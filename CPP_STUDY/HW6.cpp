#include <iostream>
#include <string.h>
using namespace std;

int my_strlen(char *, char = '\0');

int main(){
  char str[60], ch;
  cout << "���ڿ� �Է� : ";
  cin.getline(str, sizeof(str));
  cout << "���ڿ��� ���� : " << my_strlen(str) << "\n���� �Է� : ";
  cin >> ch;
  cout << ch << " ���� ������ ���� : " << my_strlen(str, ch);
}

int my_strlen(char *str, char ch){
  int cnt=0;
  while(*str != '\0' && *str != ch){
    str++; cnt++;
  }
  return cnt;
}
