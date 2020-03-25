#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  char name[20];
  int lan, eng, math;
  cout << "이름 : ";
  cin.getline(name, sizeof(name));
  cout << "세 과목의 점수 : ";
  cin >> lan >> eng >> math;
  cout << "\t\t=====< 성적표 >=====\n";
  cout << "======================================================\n";
  cout << "     이름     국어     영어     수학     총점     평균\n";
  cout << "======================================================\n";
  cout << setw(9) << name << setw(9) << lan << setw(9) << eng << setw(9) << math << setw(9) << lan+eng+math << setw(9) << setprecision(4) << (lan+eng+math)/3.0;
}
