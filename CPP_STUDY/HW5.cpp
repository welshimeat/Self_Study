#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  char name[20];
  int lan, eng, math;
  cout << "�̸� : ";
  cin.getline(name, sizeof(name));
  cout << "�� ������ ���� : ";
  cin >> lan >> eng >> math;
  cout << "\t\t=====< ����ǥ >=====\n";
  cout << "======================================================\n";
  cout << "     �̸�     ����     ����     ����     ����     ���\n";
  cout << "======================================================\n";
  cout << setw(9) << name << setw(9) << lan << setw(9) << eng << setw(9) << math << setw(9) << lan+eng+math << setw(9) << setprecision(4) << (lan+eng+math)/3.0;
}
