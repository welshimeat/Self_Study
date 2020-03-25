#include <iostream>
#include <time.h>
#include<windows.h>
#include<stdio.h>

using namespace std;
typedef struct Goods{
  char item[50];
  int price;
  int year;
  int mon;
  int day;
  int discount;
} Goods;
typedef struct date {
	unsigned int da_year;
	unsigned int da_mon;
	unsigned int da_day;
} date;

void getdate(date *);
void input(Goods &);
void selling_price(Goods &, const date &);
void prn(const Goods &);
int leap_check(int);
int tot_days(int, int, int);

int main()
{
  Goods s;
	struct date stdate;
	getdate(&stdate);
	printf("%u �� %u �� %u��\n", stdate.da_year, stdate.da_mon, stdate.da_day);

  input(s);
  selling_price(s, stdate);
  prn(s);
	return 0;
}

void getdate(date *p) // ���� �����͸� ��ȯ�Ҽ� �ֵ��� Call by pointer ��� ���
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char�迭 �ȿ� 08/10/04(��/��/��)������ ������� ���ڿ� ���·� ����
	cp = strtok(temp, "/"); // temp�迭�� ù��° '/'���� ���ڿ��� ����� cp���� "08" ���ڿ��� �����ּҸ� ����
	p->da_mon = atoi(cp); // ��� "08"���ڿ��� ������ ������ 8�� ��ȯ�Ͽ� p->da_mon�� ����
	cp = strtok(NULL, "/"); // temp�迭�� �ι�° '/'���� ���ڿ��� ����� cp���� "10" ���ڿ��� �����ּҸ� ����
	p->da_day = atoi(cp); // ��� "10"���ڿ��� ������ ������ 10�� ��ȯ�Ͽ� p->da_day�� ����
	cp = strtok(NULL, "/"); // temp�迭�� ����° '/'���� ���ڿ��� ������ϳ� '/'�� ��Ÿ���� �ʰ� ���ڿ���
							// ������ �ǹǷ� ���� ���ڿ� ��ü�� �����Ѵ� ��, cp���� "04" ���ڿ��� �����ּҰ� �����Ѵ�.
	strcat(syear, cp); // syear���� "20"�� cp�� ����Ű�� "04"�� �ٿ��� "2004" ���ڿ��� syear������ ����
	p->da_year = atoi(syear); // syear���� "2004" ���ڿ��� ������ ������ 2004�� ��ȯ�Ͽ� p->da_year�� ����
}


void input(Goods &s){
  cout << "ǰ�� �Է� : ";
  cin.getline(s.item, sizeof(s.item));
  cout << "���� �Է� : ";
  cin >> s.price;
  cout << "������� �Է� : ";
  cin >> s.year >> s.mon >> s.day;
}

void selling_price(Goods &s, const date &stdate){
  int exdate;
  exdate = tot_days(s.year, s.mon, s.day) - tot_days(stdate.da_year, stdate.da_mon, stdate.da_day);
  if(exdate < 0){
    cout << "��������� �������ϴ�!" << endl;
    s.discount = 100;
  }
  else if(exdate < 4)
    s.discount = 50;
  else if(exdate < 11)
    s.discount = 20;
  else
    s.discount = 0;
}

void prn(const Goods &s){
  cout << "ǰ�� : " << s.item << endl;
  cout << "�ǸŰ� : " << s.price * (1-s.discount/100.0) << endl;
  cout << "������� : " << s.year << "�� " << s.mon << "�� " << s.day << "��" << endl;
  cout << "������ : " << s.discount << "%" << endl;
}

int leap_check(int year){
  if(year%4 == 0){
    if(year%100 == 0){
      if(year%400 == 0)
        return 1;
      else return 0;
    }
    else return 1;
  }
  else return 0;
}

int tot_days(int year, int month, int day){
  int month2day = 0, year2day = 0;
  for(int i=1900; i<year; i++){
    if(leap_check(i) == 1)
      year2day += 366;
    else year2day += 365;
  }
  switch(month){
    case 12 : month2day += 30;
    case 11 : month2day += 31;
    case 10 : month2day += 30;
    case 9 : month2day += 31;
    case 8 : month2day += 31;
    case 7 : month2day += 30;
    case 6 : month2day += 31;
    case 5 : month2day += 30;
    case 4 : month2day += 31;
    case 3 :if(leap_check(year)==1) month2day +=29; else month2day +=28;
    case 2 : month2day += 31;
    case 1 : ;
  }
  return year2day + month2day + day;
}
