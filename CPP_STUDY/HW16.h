#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Happy
{
private:
  string name;
  int money;
  char *list[100];
  int index;
public:
  Happy(string np = "", int money = 10000);
  Happy(Happy &r);
  ~Happy();
  Happy &operator=(Happy &r);
  void use(char *lp, int n);
  Happy &winner(Happy &r);
  void setName(string &name);
  string &getName();
  void setMoney(int money);
  int getMoney();
  char **getList();
  int getIndex();
};

Happy::Happy(string np, int money){
  name = np;
  this->money = money;
  for(int i=0; i<100; i++)
    list[i] = NULL;
  index = 0;
}

Happy::Happy(Happy &r):name(r.name), money(r.money), index(r.index){
  for(int i=0; i<r.index; i++){
    list[i] = new char[strlen(r.list[i])+1];
    strcpy(list[i], r.list[i]);
  }
  for(int i=r.index; i<100; i++)
    list[i] = NULL;
}

Happy::~Happy(){
  for(int i=0; i<index; i++){
    delete[] list[i];
  }
}

Happy &Happy::operator=(Happy &r){
  for(int i=0; i<index; i++){
    delete[] list[i];
  }
  for(int i=0; i<r.index; i++){
    list[i] = new char[strlen(r.list[i])+1];
    strcpy(list[i], r.list[i]);
  }
  name = r.name;
  money = r.money;
  index = r.index;
  return *this;
}

void Happy::use(char *lp, int n){
  list[index] = new char[strlen(lp)+1];
  strcpy(list[index], lp);
  money -= n;
  index++;
}

Happy &Happy::winner(Happy &r){
  if(money > r.money)
    return *this;
  else return r;
}

void Happy::setName(string &name){
  this->name = name;
}

string &Happy::getName(){
  return name;
}

void Happy::setMoney(int money){
  this->money = money;
}
int Happy::getMoney(){
  return money;
}
char **Happy::getList(){
  return list;
}
int Happy::getIndex(){
  return index;
}
