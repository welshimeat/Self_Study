#include "listStack.h"
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
int createStack(Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	sp->head = (SNode*)malloc(sizeof(SNode));
	if(sp->head == NULL)
		return FALSE;
	sp->tail = (SNode*)malloc(sizeof(SNode));
	if(sp->tail == NULL){
		free(sp->head);
		return FALSE;
	}
	sp->head->next = sp->tail;
	sp->tail->next = sp->tail;
	return TRUE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - ������ ������ ����ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ������ ��������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
int isStackEmpty(const Stack *sp)
{
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if(sp->head->next == sp->tail)
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
	SNode *newp;
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	newp = (SNode*)malloc(sizeof(SNode));
	if(newp == NULL)
		return FALSE;
	newp->next = sp->head->next;
	sp->head->next = newp;
	newp->data = inData;
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
	SNode *curp;
	if (sp == NULL) {  /* sp������ NULL check*/
		return FALSE;
	}
	if(isStackEmpty(sp) == TRUE)
		return FALSE;
	*popData = sp->head->next->data;
	curp = sp->head->next;
	sp->head->next = sp->head->next->next;
	free(curp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp)
{
	SNode *curp;
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	if(isStackEmpty(sp) == TRUE){
		printf("Stack�� ������ϴ�!!\n");
		return;
	}
	curp = sp->head->next;
	while (curp != sp->tail)
	{
		printf("%5d\n", curp->data);
		curp = curp->next;
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	SNode *curp;
	if (sp == NULL) {  /* sp������ NULL check*/
		return;
	}
	curp = sp->head->next;
	while(curp != sp->tail){
		free(curp);
		curp = curp->next;
	}
	free(sp->head);
	free(sp->tail);
	sp->head = sp->tail = NULL;
	return;
}
