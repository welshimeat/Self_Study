#include "arrayStack.h"
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
int createStack(Stack *sp, int size)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	sp->stack = (int*)malloc(sizeof(int)*size);
	if(sp->stack == NULL)
		return FALSE;
	sp->size = size;
	sp->top = 0;
	return TRUE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - ������ �� ���ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ �� �������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
int isStackFull(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if(sp->top == sp->size)
		return TRUE;
	else return FALSE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - ������ ������ ����ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ������ ��������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if(sp->top == 0)
		return TRUE;
	else return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
inData - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int push(Stack *sp, int inData)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if(isStackFull(sp) == TRUE)
		return FALSE;
	sp->stack[sp->top] = inData;
	sp->top++;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: pop - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int pop(Stack * sp, int *popData)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if(isStackEmpty(sp) == TRUE)
		return FALSE;
	sp->top--;
	*popData = sp->stack[sp->top];
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp)
{
	int i = sp->top;
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	while (i != 0)
	{
		printf("%5d\n", sp->stack[--i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	if(sp->stack == NULL)
		return;
	free(sp->stack);
	sp->stack = NULL;
	sp->size = 0;
	sp->top = 0;
	return;  // return ���� �����ϼ���.
}
