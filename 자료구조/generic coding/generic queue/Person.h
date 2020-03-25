#pragma once
typedef struct _person {
	char* name;
	int age;
	char phone[16];
}Person;
//	p2가 가르키는 구조체변수의 내용을 p1이 가르키는 곳에 복사(깊은 복사)
void personMemCopy(void *p1, void *p2);

//	p가 가르키는 구조체변수를 초기화(name멤버가 가리키는 메모리 해제, name을 NULL로 초기화
//	age는 0으로 초기화, phone멤버는 ""으로 초기화
void personClear(void *p);

//	p가 가르키는 구조체변수의 내용을 한줄로 출력(데이터사이는 /로 구분)
void personPrint(void *p);