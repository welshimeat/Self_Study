#pragma once
//	p2가 가르키는 정수형변수의 내용을 p1이 가르키는 곳에 복사(얕은 복사)
void intMemCopy(void *p1, void *p2);

//	p가 가르키는 정수형 변수를 0으로 초기화
void intClear(void *p);

//	p가 가르키는 정수형 변수의 내용 출력
void intPrint(void *p);
