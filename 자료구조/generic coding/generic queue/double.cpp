#include "double.h"
#include <stdio.h>

//	p2�� ����Ű�� double�������� ������ p1�� ����Ű�� ���� ����(���� ����)
void doubleMemCopy(void* p1, void* p2)
{
	*(double*)p1 = *(double*)p2;
}

//	p�� ����Ű�� double�� ������ 0���� �ʱ�ȭ
void doubleClear(void* p)
{
	*(double*)p = 0;
}

//	p�� ����Ű�� double�� ������ ���� ���
void doublePrint(void* p)
{
	printf("%.2lf\n", *(double*)p);
}
