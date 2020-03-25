#include <iostream>
#include <cstring>
using namespace std;

class Fitness
{
  private :
    int num;
    char *name;
    double weight;
    double height;
  public :
    Fitness();
    Fitness(int num, char *name, double weight, double height);
    Fitness(const Fitness &r);
    ~Fitness();
    Fitness &operator=(const Fitness &r);
    bool operator==(Fitness &r);
    void setNum(int num){this->num = num;}
    int getNum(){return num;}
    void setName(char *name){delete[] this->name; this->name = new char[strlen(name)+1]; strcpy(this->name, name);}
    char *getName(){return name;}
    void setWeight(double weight){this->weight = weight;}
    double getWeight(){return weight;}
    void setHeight(double height){this->height = height;}
    double getHeight(){return height;}
    double bmi();
};

Fitness::Fitness(){
  num = 0;
  name = new char[1];
  strcpy(name, "");
  weight = 0;
  height = 0;
}

Fitness::Fitness(int num, char *name, double weight, double height){
  this->num = num;
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
  this->weight = weight;
  this->height = height;
}

Fitness::Fitness(const Fitness &r){
  num = r.num;
  name = new char[strlen(r.name)+1];
  strcpy(name, r.name);
  weight = r.weight;
  height = r.height;
}

Fitness::~Fitness(){
  delete[] name;
}

Fitness &Fitness::operator=(const Fitness &r){
  if(this == &r)
    return *this;
  delete[] name;
  name = new char[strlen(r.name)+1];
  strcpy(name, r.name);
  num = r.num;
  weight = r.weight;
  height = r.height;
  return *this;
}

bool Fitness::operator==(Fitness &r){
  if(strcmp(name, r.name) == 0)
    return true;
  else return false;
}

double Fitness::bmi(){
    double bmi = weight/(height*height*0.0001);
    return bmi;
}
