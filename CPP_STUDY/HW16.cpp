#include "HW16.h"

int main(){
  Happy a("ö��"), b("����"), w;
  char item[100];
  int price;

  cout << "ö�̰� ���� ���ϴ�..." << endl;
  while(1){
    cout << "���� ���� : ";
    cin >> item;
    if(strcmp(item, "��")==0) break;
    cout << "�ݾ� �Է� : ";
    cin >> price;
    a.use(item, price);
  }

  cout << "\n���ڰ� ���� ���ϴ�..." << endl;
  while(1){
    cout << "���� ���� : ";
    cin >> item;
    if(strcmp(item, "��")==0) break;
    cout << "�ݾ� �Է� : ";
    cin >> price;
    b.use(item, price);
  }

  cout << "\n���� ���ڴ�?" << endl;
  w=a.winner(b);
  cout << "�̸� : " << w.getName() << "�̰� �� " << w.getIndex()
       << "���� ����ϰ� ���� �ݾ��� " << w.getMoney() << "�� �Դϴ�.\n";

  cout << "��� ���� : ";
  for(int i=0; i<w.getIndex(); i++)
    cout << w.getList()[i] << "  ";
}
