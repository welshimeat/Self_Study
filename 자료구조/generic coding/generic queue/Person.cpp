#pragma warning(disable : 4996)
#include "Person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	p2가 가르키는 구조체변수의 내용을 p1이 가르키는 곳에 복사(깊은 복사)
void personMemCopy(void *p1, void *p2) {
	personClear(p1);
	if (((Person*)p2)->name != NULL) {
		//((Person*)p1)->name = (char*)calloc(sizeof(((Person*)p2)->name),sizeof(char));
		((Person*)p1)->name = (char*)calloc(strlen(((Person*)p2)->name) + 1, sizeof(char));
		strcpy(((Person*)p1)->name, ((Person*)p2)->name);
	}
	((Person*)p1)->age = ((Person*)p2)->age;
	strcpy(((Person*)p1)->phone, ((Person*)p2)->phone);
}

//	p가 가르키는 구조체변수를 초기화(name멤버가 가리키는 메모리 해제, name을 NULL로 초기화
//	age는 0으로 초기화, phone멤버는 ""으로 초기화
void personClear(void *p) {
	if (((Person*)p)->name != NULL) {
		free(((Person*)p)->name);
		((Person*)p)->name = NULL;
	}
	((Person*)p)->age = 0;
	strcpy(((Person*)p)->phone, "");
}

//	p가 가르키는 구조체변수의 내용을 한줄로 출력(데이터사이는 /로 구분)
void personPrint(void *p) {
	printf("성명 : %s / 나이 : %d/ 전화번호 : %s\n", ((Person*)p)->name, ((Person*)p)->age, ((Person*)p)->phone);
}