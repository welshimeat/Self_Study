#include <iostream>
using namespace std;
#include "HW18.h"


int main(){
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(2);
  SmartArray cheol(3), metel(5);
  int total=0, temp;
  double avg;
  cout << "ö���� �� ������ ���� �Է� : ";
  for(int i=0; i<cheol.getSize(); i++){
    cin >> temp;
    cheol.put(i, temp);
    total += cheol.getAry()[i];
  }
  avg = total/3.0;
  cout << "ö���� ���� : " << total << endl;
  cout << "ö���� ��� : " << avg << endl;
  cout << "������ �ټ� ������ ���� �Է� : ";
  total = 0;
  for(int i=0; i<metel.getSize(); i++){
    cin >> temp;
    metel.put(i, temp);
    total += metel.getAry()[i];
  }
  avg = total/5.0;
  cout << "������ ���� : " << total << endl;
  cout << "������ ��� : " << avg << endl;
  if(cheol.getMax() < metel.getMax())
    cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�..." << endl;
  else
    cout << "������ �ְ����� ö�̺��� ũ�� �ʴ�..." << endl;
  return 0;
}
