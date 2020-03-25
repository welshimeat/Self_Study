#include <iostream>
#include <cstring>
#pragma warning (disable : 4996)
using  namespace std;

class Save{
  private :
    char name[20];
    int capital;
    double profit;
    double tax;
    int tot;
    static double ratio;
  public:
    static double tax_ratio;
    Save(const char *np = "아무개", int n = 0);
    void calculate();
    static void set_ratio(double r){ ratio = r;};
    char *getName(){ return this->name;};
    int getCapital(){ return this->capital;};
    int getProfit(){ return this->profit;};
    int getTax(){ return this->tax;};
    int getTot(){ return this->tot;};
    double getRatio(){ return this->ratio;};
    double getTax_ratio(){ return this->tax_ratio;};
    void setProfit(){ this->profit = this->capital * ratio;};
    void setTax(){ this->tax = this->profit * this->tax_ratio;};
};

double Save::tax_ratio = 0.1;
double Save::ratio = 0.2;

Save::Save(const char *np, int n){
  strcpy(this->name, np);
  this->capital = n;
}
void Save::calculate(){
  this->tot = this->capital + this->profit - this->tax;
}

int main(){
  Save a("철이", 1000000), b("메텔", 2000000);
  a.setProfit();
  a.setTax();
  a.calculate();

  cout << "이름 : " << a.getName() << endl;
  cout << "원금 : " << a.getCapital() << endl;
  cout << "이자소득 : " << a.getProfit() << endl;
  cout << "세금 : " << a.getTax() << endl;
  cout << "총금액 : " << a.getTot() << endl;
  cout << "이율 : " << a.getRatio() << endl;
  cout << "세율 : " << a.getTax_ratio() << endl << endl;

  Save::tax_ratio = 0.15;
  Save::set_ratio(0.25);
  b.setProfit();
  b.setTax();
  b.calculate();

  cout << "이름 : " << b.getName() << endl;
  cout << "원금 : " << b.getCapital() << endl;
  cout << "이자소득 : " << b.getProfit() << endl;
  cout << "세금 : " << b.getTax() << endl;
  cout << "총금액 : " << b.getTot() << endl;
  cout << "이율 : " << b.getRatio() << endl;
  cout << "세율 : " << b.getTax_ratio() << endl << endl;
  return 0;
}
