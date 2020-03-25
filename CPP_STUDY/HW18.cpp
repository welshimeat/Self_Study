#include <iostream>
using namespace std;
#include "HW18.h"


int main(){
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  SmartArray cheol(3), metel(5);
  int total=0, temp;
  double avg;
  cout << "철이의 세 과목의 점수 입력 : ";
  for(int i=0; i<cheol.getSize(); i++){
    cin >> temp;
    cheol.put(i, temp);
    total += cheol.getAry()[i];
  }
  avg = total/3.0;
  cout << "철이의 총점 : " << total << endl;
  cout << "철이의 평균 : " << avg << endl;
  cout << "메텔의 다섯 과목의 점수 입력 : ";
  total = 0;
  for(int i=0; i<metel.getSize(); i++){
    cin >> temp;
    metel.put(i, temp);
    total += metel.getAry()[i];
  }
  avg = total/5.0;
  cout << "메텔의 총점 : " << total << endl;
  cout << "메텔의 평균 : " << avg << endl;
  if(cheol.getMax() < metel.getMax())
    cout << "철이의 최고점은 메텔보다 크지 않다..." << endl;
  else
    cout << "메텔의 최고점은 철이보다 크지 않다..." << endl;
  return 0;
}
