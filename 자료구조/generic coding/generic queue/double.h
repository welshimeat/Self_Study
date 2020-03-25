#pragma once
//	p2가 가르키는 double형변수의 내용을 p1이 가르키는 곳에 복사(얕은 복사)
void doubleMemCopy(void* p1, void* p2);

//	p가 가르키는 double형 변수를 0으로 초기화
void doubleClear(void* p);

//	p가 가르키는 double형 변수의 내용 출력
void doublePrint(void* p);
