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
    Save(const char *np = "�ƹ���", int n = 0);
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
  Save a("ö��", 1000000), b("����", 2000000);
  a.setProfit();
  a.setTax();
  a.calculate();

  cout << "�̸� : " << a.getName() << endl;
  cout << "���� : " << a.getCapital() << endl;
  cout << "���ڼҵ� : " << a.getProfit() << endl;
  cout << "���� : " << a.getTax() << endl;
  cout << "�ѱݾ� : " << a.getTot() << endl;
  cout << "���� : " << a.getRatio() << endl;
  cout << "���� : " << a.getTax_ratio() << endl << endl;

  Save::tax_ratio = 0.15;
  Save::set_ratio(0.25);
  b.setProfit();
  b.setTax();
  b.calculate();

  cout << "�̸� : " << b.getName() << endl;
  cout << "���� : " << b.getCapital() << endl;
  cout << "���ڼҵ� : " << b.getProfit() << endl;
  cout << "���� : " << b.getTax() << endl;
  cout << "�ѱݾ� : " << b.getTot() << endl;
  cout << "���� : " << b.getRatio() << endl;
  cout << "���� : " << b.getTax_ratio() << endl << endl;
  return 0;
}
