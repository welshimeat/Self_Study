#include <iostream>
using namespace std;

void swap_ptr(const char *&, const char *&);

int main(){
  const char *ap = "apple";
  const char *bp = "banana";

  cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
  swap_ptr(ap, bp);
  cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;

  return 0;
}

void swap_ptr(const char *&p1, const char *&p2){
  const char *temp;
  temp = p1;
  p1 = p2;
  p2 = temp;
}
