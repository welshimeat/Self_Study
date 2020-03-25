#include "HW17.h"

class SmartArray : public MyArray
{
private :
  int max;
public :
  SmartArray(){}
  SmartArray(int s) : MyArray(s), max(0){}
  bool put(int index, int val);
  int getMax();
  bool operator>(const SmartArray &br);
};

bool SmartArray::put(int index, int val){
  if(index<0 || index>=getSize())
    return false;
  else{
    getAry()[index] = val;
    if(val > max)
      max = val;
    return true;
  }
}

int SmartArray::getMax(){
  return max;
}

bool SmartArray::operator>(const SmartArray &br){
  if(max > br.max)
    return true;
  else return false;
}
