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
	printf("%u 년 %u 월 %u일\n", stdate.da_year, stdate.da_mon, stdate.da_day);

  input(s);
  selling_price(s, stdate);
  prn(s);
	return 0;
}

void getdate(date *p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char배열 안에 08/10/04(월/일/년)순으로 년월일이 문자열 상태로 저장
	cp = strtok(temp, "/"); // temp배열의 첫번째 '/'까지 문자열를 끊어내어 cp에게 "08" 문자열의 시작주소를 리턴
	p->da_mon = atoi(cp); // 끊어낸 "08"문자열을 정수형 데이터 8로 변환하여 p->da_mon에 저장
	cp = strtok(NULL, "/"); // temp배열의 두번째 '/'까지 문자열를 끊어내어 cp에게 "10" 문자열의 시작주소를 리턴
	p->da_day = atoi(cp); // 끊어낸 "10"문자열을 정수형 데이터 10로 변환하여 p->da_day에 저장
	cp = strtok(NULL, "/"); // temp배열의 세번째 '/'까지 문자열를 끊어내려하나 '/'은 나타나지 않고 문자열이
							// 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 "04" 문자열의 시작주소가 리턴한다.
	strcat(syear, cp); // syear내의 "20"과 cp가 가리키는 "04"을 붙여서 "2004" 문자열을 syear변수에 저장
	p->da_year = atoi(syear); // syear내의 "2004" 문자열을 정수형 데이터 2004로 변환하여 p->da_year에 저장
}


void input(Goods &s){
  cout << "품목 입력 : ";
  cin.getline(s.item, sizeof(s.item));
  cout << "정가 입력 : ";
  cin >> s.price;
  cout << "유통기한 입력 : ";
  cin >> s.year >> s.mon >> s.day;
}

void selling_price(Goods &s, const date &stdate){
  int exdate;
  exdate = tot_days(s.year, s.mon, s.day) - tot_days(stdate.da_year, stdate.da_mon, stdate.da_day);
  if(exdate < 0){
    cout << "유통기한이 지났습니다!" << endl;
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
  cout << "품목 : " << s.item << endl;
  cout << "판매가 : " << s.price * (1-s.discount/100.0) << endl;
  cout << "유통기한 : " << s.year << "년 " << s.mon << "월 " << s.day << "일" << endl;
  cout << "할인율 : " << s.discount << "%" << endl;
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
