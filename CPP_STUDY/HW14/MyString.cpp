#include "MyString.h"
#include <cstring>
#pragma warning (disable : 4996)
MyString::MyString(){
  str = new char[1];
  strcpy(str, "");
  len = 0;
}

MyString::MyString(const char* cp){
  len = strlen(cp);
  str = new char[len+1];
  strcpy(str, cp);
}

MyString::MyString(const MyString& br){
  len = br.len;
  str = new char[len+1];
  strcpy(str, br.str);
}

MyString::~MyString(){
  delete[] str;
}

MyString& MyString::operator=(const MyString& br){
  if(*this == br)
    return *this;
  delete[] str;
  len = br.len;
  str = new char[len+1];
  strcpy(str, br.str);
  return *this;
}

MyString MyString::operator+(const MyString& br){
  char *temp;
  temp = new char[len+br.len+1];
  strcpy(temp, str);
  strcat(temp, br.str);
  return MyString(temp);
}

MyString MyString::operator*(int n){
  char *temp;
  temp = new char[len*n+1];
  strcpy(temp, str);
  for(int i=0; i<n-1; i++)
    strcat(temp, str);
  return MyString(temp);
}

MyString &MyString::operator+=(const char *p){
  char *temp;
  len += strlen(p);
  temp = new char[len+1];
  strcpy(temp, str);
  strcat(temp, p);
  delete[] str;
  str = new char[len+1];
  strcpy(str, temp);
  delete[] temp;
  return *this;
}

bool MyString::find(const char *p){
  int length = strlen(p);
  for(int i=0; i<len-length; i++){
    if(strncmp(str+i, p, length) == 0)
      return true;
  }
  return false;
}

bool MyString::operator>(const MyString& br){
  if(len>br.len)
    return true;
  else return false;
}

bool MyString::operator==(const MyString& br){
  if(len == br.len)
    return true;
  else return false;
}

bool MyString::operator<(const MyString& br){
  if(len < br.len)
    return true;
  else return false;
}

ostream& operator<<(ostream& os, MyString &br){
  os << br.str << "(" << br.len << ")";
  return os;
}

istream& operator>>(istream& is, MyString &br){
  char temp[60];
  is >> temp;
  br.str = new char[strlen(temp)+1];
  strcpy(br.str, temp);
  br.len = strlen(temp);
  return is;
}
