#include "arrayStack.h"
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
				  dataSize - ������ �ϳ��� ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size, size_t dataSize)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	sp->stack = calloc(size, dataSize);  /* stack �޸� �Ҵ� */
	if (sp->stack != NULL) {	/* stack �޸� �Ҵ� ���� ��*/
		sp->size = size;	/* ���� size �ʱ�ȭ */
		sp->top = 0;		/* top 0���� �ʱ�ȭ */
		return TRUE;
	}
	else {	/* stack �޸� �Ҵ� ���� �� */
		return FALSE;
	}
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - ������ �� ���ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ �� �������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if (sp->top == sp->size)  /* stack�� �� �������� */
		return TRUE;
	else
		return FALSE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - ������ ������ ����ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ������ ��������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if (sp->top == 0)  /* stack�� ��������� */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  inData - ���ÿ� ������ �����Ϳ����� �����ּ�
				  dataSize - ������ �ϳ��� ũ��
				  memCpy - push�� �����͸� �������ִ� �Լ��� �����ּҸ� �����ϴ� �Լ� ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, void *inData, size_t dataSize, void(*memCpy)(void*, void*))
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if (isStackFull(sp)) {  /* stack�� �� �������� */
		return FALSE;
	}
	else {					/* �����͸� top ��ġ�� ������ �� top�� ������Ŵ */
		//sp->stack[sp->top] = inData;
		memCpy((char*)sp->stack + sp->top * dataSize, inData);
		sp->top++;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: pop - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  popData - ���� �����͸� ������ �������� �ּ�
				  dataSize - ������ �ϳ��� ũ��(�ּҰ�� �� ���)
				  memCpy - pop�� �����͸� �������ִ� �Լ��� �����ּҸ� �����ϴ� �Լ� ������
				  memClear - pop�� ������ �ʱ�ȭ �����ִ� �Լ��� �����ּҸ� �����ϴ� �Լ� ������
popData -  ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL pop(Stack *sp, void *popData, size_t dataSize, void(*memCpy)(void*, void*), void(*clear)(void*))
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}

	if (isStackEmpty(sp)) {  /* stack�� ��������� */
		return FALSE;
	}
	else {	/* �����͸� top-1�� ��ġ���� ���� popData�� ����Ű�� ���� ���� �� */
		--sp->top;
		memCpy(popData, (char*)sp->stack +sp->top*dataSize);
		//*popData = sp->stack[sp->top]; <<== memcpy �Լ� �����͸� �̿��ؼ� ��������
		// <<== clear �Լ������͸� �̿��ؼ� pop�� ������ �ʱ�ȭ(Clear)���ֱ�
		clear((char*)sp->stack + sp->top * dataSize);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  dataSize - ������ �ϳ��� ũ��
				  print - �����͸� ����� �Լ��� �����ּҸ� �����ϴ� �Լ� ������ ����
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp, size_t dataSize, void(*print)(void*))
{
	int i = sp->top;
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	while (i != 0)
	{
		//printf("%5d\n", sp->stack[--i]);
		print((char*)sp->stack + --i * dataSize);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp, size_t dataSize, void(*clear)(void*))
{
	int i = sp->top;
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	while (i != 0) {
		clear((char*)sp->stack + --i * dataSize);
	}
	if (sp->stack != NULL) {	/* statck���� ���Ǵ� �迭 �޸� ���� */
		free(sp->stack);
	}
	sp->stack = NULL;	/* stack ����� NULL pointer�� �ʱ�ȭ */
	sp->size = 0;		/* size�� top����� 0���� �ʱ�ȭ */
	sp->top = 0;
}
