#include "int.h"
#include <stdio.h>

//	p2�� ����Ű�� ������������ ������ p1�� ����Ű�� ���� ����(���� ����)
void intMemCopy(void *p1, void *p2)
{
  *(int*)p1 = *(int*)p2;
}

//	p�� ����Ű�� ������ ������ 0���� �ʱ�ȭ
void intClear(void *p)
{
  *(int*)p = 0;
}

//	p�� ����Ű�� ������ ������ ���� ���
void intPrint(void *p)
{
  printf("%d\n", *(int*)p);
}
