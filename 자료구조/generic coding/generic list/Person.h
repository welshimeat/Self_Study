#pragma once
typedef struct _person {
	char* name;
	int age;
	char phone[16];
}Person;
//	p2�� ����Ű�� ����ü������ ������ p1�� ����Ű�� ���� ����(���� ����)
void personMemCopy(void *p1, void *p2);

//	p�� ����Ű�� ����ü������ �ʱ�ȭ(name����� ����Ű�� �޸� ����, name�� NULL�� �ʱ�ȭ
//	age�� 0���� �ʱ�ȭ, phone����� ""���� �ʱ�ȭ
void personClear(void *p);

//	p�� ����Ű�� ����ü������ ������ ���ٷ� ���(�����ͻ��̴� /�� ����)
void personPrint(void *p);

//	p1->name�� p2->name���� ũ�� 1, ������ 0, ������ -1 ����
int personNameCompare(void *p1, void *p2);

//	p1->age�� p2->age���� ũ�� 1, ������ 0, ������ -1 ����
int personAgeCompare(void *p1, void *p2);