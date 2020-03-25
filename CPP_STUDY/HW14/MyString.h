#include<iostream>
using namespace std;
class MyString {
private:
	char* str; // 문자열을 연결할 포인터멤버
	int len; // 문자열의 길이를 저장
public:
	MyString(); // "", 0으로 초기화
	MyString(const char* cp); // 오버로디드 생성자
	MyString(const MyString& br); // 복사 생성자 (깊은 복사)
	~MyString(); // 리소스 반납
	MyString& operator=(const MyString& br); // 깊은 복사
	MyString operator+(const MyString& br); // 덧셈 연산자
	MyString operator*(int n); // 문자열을 n번 반복되는 문자열로 만들어 리턴
	MyString &operator+=(const char* p); // 문자열에 전달된 문자열을 붙여서 저장
	bool find(const char* p); // 문자열 내에 전달된 문자열이 존재하는가 검사
	bool operator>(const MyString& br); // 관계연산자 멤버함수(길이 비교)
	bool operator==(const MyString& br); // 길이같은가 검사
	bool operator<(const MyString& br); // 길이 짧은가 검사

	friend ostream& operator<<(ostream& os, MyString &); // 출력연산자 멤버함수
	friend istream& operator>>(istream& is, MyString &); // 입력연산자 멤버함수
};
