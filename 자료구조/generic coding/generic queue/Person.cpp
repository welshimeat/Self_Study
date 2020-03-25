#pragma warning(disable : 4996)
#include "Person.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	p2�� ����Ű�� ����ü������ ������ p1�� ����Ű�� ���� ����(���� ����)
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

//	p�� ����Ű�� ����ü������ �ʱ�ȭ(name����� ����Ű�� �޸� ����, name�� NULL�� �ʱ�ȭ
//	age�� 0���� �ʱ�ȭ, phone����� ""���� �ʱ�ȭ
void personClear(void *p) {
	if (((Person*)p)->name != NULL) {
		free(((Person*)p)->name);
		((Person*)p)->name = NULL;
	}
	((Person*)p)->age = 0;
	strcpy(((Person*)p)->phone, "");
}

//	p�� ����Ű�� ����ü������ ������ ���ٷ� ���(�����ͻ��̴� /�� ����)
void personPrint(void *p) {
	printf("���� : %s / ���� : %d/ ��ȭ��ȣ : %s\n", ((Person*)p)->name, ((Person*)p)->age, ((Person*)p)->phone);
}