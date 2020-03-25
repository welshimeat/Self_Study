#include <iostream>
using namespace std;

class Time{
private:
  int hour;
  int min;
  double time;
  static int mode;
  enum {integer, real};
public:
  Time();
  Time(int a, int b){hour = a; min = b; time = hour + (double)min/60;};
  Time(double a){time = a; hour = (int)a; min = (a-hour)*60;};
  Time(const Time &tr){hour = tr.hour; min = tr.min; time = tr.time;};
  Time plus(const Time &tr);
  void setHour(int a){hour = a;};
  int getHour(){return hour;};
  void setMin(int a){min = a;};
  int getMin(){return min;};
  friend ostream &operator<<(ostream &os, const Time &br);
  static void mode_change(){if(mode == 0) mode = 1; else mode = 0;};
};

Time Time::plus(const Time &tr){
  int h, m;
  h = hour + tr.hour;
  m = min + tr.min;
  if(m>=60){
    h += m/60;
    m = m%60;
  }
  return Time(h, m);
}

ostream &operator<<(ostream &os, const Time &br){
  if(br.mode == 0)
    os << br.hour << "시간 " << br.min << "분";
  else
    os << br.time << "시간";
  return os;
}

int Time::mode = 0;

int main()
{
  Time a(3, 21);
  Time b(2.7);
  cout << "기본 출력 형태(시간, 분)..." << endl;
  cout << a << endl;
  cout << b << endl;
  Time::mode_change();
  cout << "출력모드를 바꾼 후..." << endl;
  cout << "기본 출력 형태(시간, 분)..." << endl;
  cout << a << endl;
  cout << b << endl;
  return 0;
}
