#include "listStack.h"
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - 지정된 크기의 스택을 생성하는 함수
Parameters		: sp - 스택관리 구조체의 주소
				  size - 스택의 크기
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int createStack(Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
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
Function name	: isStackEmpty - 스택이 완전히 비어있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 완전히 비어있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
int isStackEmpty(const Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if(sp->head->next == sp->tail)
		return TRUE;
	else return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택관리 구조체의 주소
inData - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int push(Stack *sp, int inData)
{
	SNode *newp;
	if (sp == NULL) {  /* sp포인터 NULL check*/
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
Function name	: pop - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택관리 구조체의 주소
popData -  꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int pop(Stack * sp, int *popData)
{
	SNode *curp;
	if (sp == NULL) {  /* sp포인터 NULL check*/
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
Function name	: printStack - 스택의 모든 데이터 출력(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp)
{
	SNode *curp;
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return;
	}
	if(isStackEmpty(sp) == TRUE){
		printf("Stack이 비었습니다!!\n");
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
Function name	: destroyStack -  스택 소멸 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	SNode *curp;
	if (sp == NULL) {  /* sp포인터 NULL check*/
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
