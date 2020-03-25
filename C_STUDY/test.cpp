#include <iostream>
using namespace std;

namespace lectopia{
  double CircleArea(int r){
    return r*r*3.14;
  }
  int RectArea(int h, int w){
    return h*w;
  }
}

class Math
{
public:
    static double CircleArea(int r){
      return r*r*3.14;
    }
    static int RectArea(int h, int w){
      return h*w;
    }
};
int main(){
  cout << Math::CircleArea(5) << endl;
  cout << Math::RectArea(3,6) << endl;
  cout << lectopia::CircleArea(5) << endl;
  cout << lectopia::RectArea(3,6) << endl;
}
