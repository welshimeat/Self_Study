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
  const char *menu[6] = {"회원등록", "회원전체보기", "회원정보검색", "회원탈퇴", "특별관리 회원", "종료"};
  cout << "회원 관리 메뉴" << endl;
  for(int i=0; i<6; i++){
    cout << i+1 << ".  " << menu[i] << endl;
  }
  cout << "메뉴 선택 : ";
  cin >> input;
  while(input<1 || input >6){
    while(cin.get() != '\n')
      ;
    cout << "메뉴 선택 : ";
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
    cout << "최대 가입 회원 수 초과" << endl;
    return;
  }
  cout << "회원 이름 입력 : ";
  cin >> name;
  cout << "회원 몸무게(kg단위) 입력 : ";
  cin >> weight;
  cout << "회원 신장(키-cm단위) 입력 : ";
  cin >> height;
  fary[*memberCnt] = new Fitness;
  *fary[*memberCnt] = Fitness(++num, name, weight, height);
  cout << "회원 등록 완료" << endl;
  (*memberCnt)++;
}

void printMember(Fitness **fary, int memberCnt){
  for(int i=0; i<memberCnt; i++){
    cout << "회원번호 : " << fary[i]->getNum() << "/ 이름 : " << fary[i]->getName() << "/ 몸무게 : " << fary[i]->getWeight() << "/ 신장 : " << fary[i]->getHeight() << endl;
  }
}

void searchMember(Fitness **fary, int memberCnt){
  bool Switch = false;
  char temp[60];
  Fitness tempFit;
  cout << "검색할 이름 입력 : ";
  cin >> temp;
  tempFit.setName(temp);
  for(int i=0; i<memberCnt; i++){
    if(tempFit == *fary[i]){
      cout << "회원번호 : " << fary[i]->getNum() << "/ 이름 : " << fary[i]->getName() << "/ 몸무게 : " << fary[i]->getWeight() << "/ 신장 : " << fary[i]->getHeight() << endl;
      Switch = true;
    }
  }
  if(Switch == false){
    cout << "존재하지 않는 회원입니다." << endl;
  }
}

void deleteMember(Fitness **fary, int *memberCnt){
  int i, num;
  cout << "탈퇴할 회원 번호 입력 : ";
  cin >> num;
  for(i=0; i<*memberCnt; i++){
    if(num == fary[i]->getNum()){
      delete fary[i];
      break;
    }
  }
  if(i == *memberCnt){
    cout << "존재하지 않는 회원 번호입니다." << endl;
    return;
  }
  for(; i<*memberCnt-1; i++){
    fary[i] = fary[i+1];
  }
  cout << "회원 탈퇴 완료" << endl;
  (*memberCnt)--;
}

void specialMember(Fitness **fary, int memberCnt){
  bool Switch = false;
  for(int i=0; i<memberCnt; i++){
    if(fary[i]->bmi() > 25.0){
      cout << "회원번호 : " << fary[i]->getNum() << "/ 이름 : " << fary[i]->getName() << "/ 몸무게 : " << fary[i]->getWeight() << "/ 신장 : " << fary[i]->getHeight() << endl;
      Switch = true;
    }
  }
  if(Switch == false)
    cout << "존재하는 특별 회원이 없습니다." << endl;
}
