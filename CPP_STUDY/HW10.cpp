#include <iostream>
using namespace std;

class Time{
private:
  int hour;
  int min;
public:
  Time(){hour=0; min=0;};
  Time(int a,int b){hour=a; min=b;};
  Time(double a){
    this->hour = a;
    this->min = (a-this->hour)*60;
  };
  //Time(const Time &tr);
  Time plus(const Time &tr);
  void setHour(int a){this->hour = a;};
  int getHour(){ return this->hour;};
  void setMin(int a){this->min = a;};
  int getMin() { return this->min;};
};

int main(){
  Time a(3,20), b;
  cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
  b.setHour(4);
  b.setMin(42);
  cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
  Time res = a.plus(b);
  cout << "두 시간을 더하면 : " << res.getHour() << "시간 " << res.getMin() << "분" << endl;
  return 0;
}

// Time::Time(const Time &tr){
//   this->min = tr.min;
//   this->hour = tr.hour;
// };


Time Time::plus(const Time &tr){
  this->setHour(this->hour + tr.hour + (this->min+tr.min)/60);
  this->setMin((this->min + tr.min)%60);
  return *this;
}
