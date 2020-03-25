#include <iostream>
#include <string>
using namespace std;

class Machine{
  string _name;
public :
  Machine(const string& name) : _name(name){}
};

class Tv : public Machine{
  public :
    Tv(const char* name) : Machine(name){}
};

class Phone : public Machine{
  public :
    Phone(){}
};

int main(){

  return 0;
}

//복사 대입 소멸자 복사 test 소멸자
