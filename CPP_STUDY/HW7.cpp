#include <iostream>
using namespace std;
typedef struct Savings{
  int w500;
  int w100;
  int w50;
  int w10;
}Savings;
void init(Savings &);
void input(int &, int &);
void save(Savings &, int, int);
int total(Savings &);

int main(){
  Savings s;
  int unit, cnt;

  init(s);
  while(1){
      input(unit, cnt);
      if(unit == -1) break;
      save(s, unit, cnt);
  }
  cout << total(s);
}

void init(Savings &s){
  s.w500 = 0;
  s.w100 = 0;
  s.w50 = 0;
  s.w10 = 0;
}

void input(int &unit, int &cnt){
  unit = 0;
  cnt = 0;
  cout << "동전의 금액 : " ;
  cin >> unit;
  while(unit != 500 && unit != 100 && unit != 50 && unit != 10){
    if(cin.fail()){
      cin.clear();
      unit = -1;
      return;
    }
    cout << "동전의 금액 : " ;
    cin >> unit;
  }
  cout << "동전의 개수 : ";
  cin >> cnt;
  while(cnt<0 || cin.fail()){
    cin.clear();
    while(getchar() != '\n')
      ;
    cout << "동전의 개수 : ";
    cin >> cnt;
  }
}

void save(Savings &s, int unit, int cnt){
  switch(unit){
    case 500 : s.w500 += cnt; break;
    case 100 : s.w100 += cnt; break;
    case 50 : s.w50 += cnt; break;
    case 10 : s.w10 += cnt; break;
  }
}

int total(Savings &s){
  printf("총 저금액 : ");
  return s.w500 * 500 + s.w100 * 100 + s.w50 * 50 + s.w10 * 10;
}
