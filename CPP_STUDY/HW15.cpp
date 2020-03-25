#include "HW15.h"

int inputMenu();
void memberReg(Fitness **, int *);
void printMember(Fitness **, int);
void searchMember(Fitness **, int);
void deleteMember(Fitness **, int *);
void specialMember(Fitness **, int);

int main(){
  Fitness *fary[100];
  int memberCnt=0;

  while(1){
    switch(inputMenu()){
      case 1 : memberReg(fary, &memberCnt); break;
      case 2 : printMember(fary, memberCnt); break;
      case 3 : searchMember(fary, memberCnt); break;
      case 4 : deleteMember(fary, &memberCnt); break;
      case 5 : specialMember(fary, memberCnt); break;
      case 6 : for(int i=0; i<memberCnt; i++) delete fary[i]; return 0;
    }
  }
}

int inputMenu(){
  int input;
  const char *menu[6] = {"ȸ�����", "ȸ����ü����", "ȸ�������˻�", "ȸ��Ż��", "Ư������ ȸ��", "����"};
  cout << "ȸ�� ���� �޴�" << endl;
  for(int i=0; i<6; i++){
    cout << i+1 << ".  " << menu[i] << endl;
  }
  cout << "�޴� ���� : ";
  cin >> input;
  while(input<1 || input >6){
    while(cin.get() != '\n')
      ;
    cout << "�޴� ���� : ";
    cin >> input;
  }
  return input;
}

void memberReg(Fitness **fary, int *memberCnt){
  static int num = 0;
  char name[60];
  double weight;
  double height;
  if(*memberCnt > 100){
    cout << "�ִ� ���� ȸ�� �� �ʰ�" << endl;
    return;
  }
  cout << "ȸ�� �̸� �Է� : ";
  cin >> name;
  cout << "ȸ�� ������(kg����) �Է� : ";
  cin >> weight;
  cout << "ȸ�� ����(Ű-cm����) �Է� : ";
  cin >> height;
  fary[*memberCnt] = new Fitness;
  *fary[*memberCnt] = Fitness(++num, name, weight, height);
  cout << "ȸ�� ��� �Ϸ�" << endl;
  (*memberCnt)++;
}

void printMember(Fitness **fary, int memberCnt){
  for(int i=0; i<memberCnt; i++){
    cout << "ȸ����ȣ : " << fary[i]->getNum() << "/ �̸� : " << fary[i]->getName() << "/ ������ : " << fary[i]->getWeight() << "/ ���� : " << fary[i]->getHeight() << endl;
  }
}

void searchMember(Fitness **fary, int memberCnt){
  bool Switch = false;
  char temp[60];
  Fitness tempFit;
  cout << "�˻��� �̸� �Է� : ";
  cin >> temp;
  tempFit.setName(temp);
  for(int i=0; i<memberCnt; i++){
    if(tempFit == *fary[i]){
      cout << "ȸ����ȣ : " << fary[i]->getNum() << "/ �̸� : " << fary[i]->getName() << "/ ������ : " << fary[i]->getWeight() << "/ ���� : " << fary[i]->getHeight() << endl;
      Switch = true;
    }
  }
  if(Switch == false){
    cout << "�������� �ʴ� ȸ���Դϴ�." << endl;
  }
}

void deleteMember(Fitness **fary, int *memberCnt){
  int i, num;
  cout << "Ż���� ȸ�� ��ȣ �Է� : ";
  cin >> num;
  for(i=0; i<*memberCnt; i++){
    if(num == fary[i]->getNum()){
      delete fary[i];
      break;
    }
  }
  if(i == *memberCnt){
    cout << "�������� �ʴ� ȸ�� ��ȣ�Դϴ�." << endl;
    return;
  }
  for(; i<*memberCnt-1; i++){
    fary[i] = fary[i+1];
  }
  cout << "ȸ�� Ż�� �Ϸ�" << endl;
  (*memberCnt)--;
}

void specialMember(Fitness **fary, int memberCnt){
  bool Switch = false;
  for(int i=0; i<memberCnt; i++){
    if(fary[i]->bmi() > 25.0){
      cout << "ȸ����ȣ : " << fary[i]->getNum() << "/ �̸� : " << fary[i]->getName() << "/ ������ : " << fary[i]->getWeight() << "/ ���� : " << fary[i]->getHeight() << endl;
      Switch = true;
    }
  }
  if(Switch == false)
    cout << "�����ϴ� Ư�� ȸ���� �����ϴ�." << endl;
}
