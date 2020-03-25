#include "MyString.h"
int main()
{
	MyString ary[5]; // 객체 배열
	MyString res; // 문자열을 모두 붙여서 저장할 객체
	int i;
	cout << "5개의 과일이름 입력 : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i]; // 입력연산자 사용
	}
	cout << "첫번째와 두번째 중 긴 과일 이름 : ";
	if (ary[0] > ary[1]) { // 관계연산자 사용
		cout << ary[0] << endl; // 출력연산자 사용
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4]; // 덧셈연산자 사용
	cout << "모든 문자열 출력:" << res << endl;
	cout << "배열내의 문자열 출력..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}

	MyString ob1("Have a nice day!!~");
	if (ob1.find("nice") == true) {
		cout << "해당문자열이 존재합니다." << endl;
	}
	else {
		cout << "해당문자열이 존재하지 않습니다." << endl;
	}
	if (ob1.find("good") == true) {
		cout << "해당문자열이 존재합니다." << endl;
	}
	else {
		cout << "해당문자열이 존재하지 않습니다." << endl;
	}
	MyString ob2("star");
	MyString res2;
	res2 = ob2 * 3;
	cout << res2;
	ob2 += " & moon";
	cout << ob2;

	(ob1 > ob2) ? cout << ob1 : cout << ob2; // 두 객체중 더 긴문자열 출력하기

	return 0;
}
