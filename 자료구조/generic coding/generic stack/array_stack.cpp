#include "arrayStack.h"
#include <stdio.h>
#include <stdlib.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - 지정된 크기의 스택을 생성하는 함수
Parameters		: sp - 스택관리 구조체의 주소
				  size - 스택의 크기
				  dataSize - 데이터 하나의 크기
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size, size_t dataSize)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	sp->stack = calloc(size, dataSize);  /* stack 메모리 할당 */
	if (sp->stack != NULL) {	/* stack 메모리 할당 설공 시*/
		sp->size = size;	/* 스택 size 초기화 */
		sp->top = 0;		/* top 0으로 초기화 */
		return TRUE;
	}
	else {	/* stack 메모리 할당 실패 시 */
		return FALSE;
	}
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - 스택이 꽉 차있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 꽉 차있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if (sp->top == sp->size)  /* stack이 꽉 차있으면 */
		return TRUE;
	else
		return FALSE;
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - 스택이 완전히 비어있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 완전히 비어있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if (sp->top == 0)  /* stack이 비어있으면 */
		return TRUE;
	else
		return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: push - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택관리 구조체의 주소
				  inData - 스택에 저장할 데이터영역의 시작주소
				  dataSize - 데이터 하나의 크기
				  memCpy - push할 데이터를 복사해주는 함수의 시작주소를 저장하는 함수 포인터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, void *inData, size_t dataSize, void(*memCpy)(void*, void*))
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}
	if (isStackFull(sp)) {  /* stack이 꽉 차있으면 */
		return FALSE;
	}
	else {					/* 데이터를 top 위치에 저장한 후 top을 증가시킴 */
		//sp->stack[sp->top] = inData;
		memCpy((char*)sp->stack + sp->top * dataSize, inData);
		sp->top++;
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: pop - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택관리 구조체의 주소
				  popData - 꺼낸 데이터를 저장할 기억공간의 주소
				  dataSize - 데이터 하나의 크기(주소계산 시 사용)
				  memCpy - pop할 데이터를 복사해주는 함수의 시작주소를 저장하는 함수 포인터
				  memClear - pop한 영역을 초기화 시켜주는 함수의 시작주소를 저장하는 함수 포인터
popData -  꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
BOOL pop(Stack *sp, void *popData, size_t dataSize, void(*memCpy)(void*, void*), void(*clear)(void*))
{
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return FALSE;
	}

	if (isStackEmpty(sp)) {  /* stack이 비어있으면 */
		return FALSE;
	}
	else {	/* 데이터를 top-1번 위치에서 꺼내 popData가 가리키는 곳에 저장 함 */
		--sp->top;
		memCpy(popData, (char*)sp->stack +sp->top*dataSize);
		//*popData = sp->stack[sp->top]; <<== memcpy 함수 포인터를 이용해서 깊은복사
		// <<== clear 함수포인터를 이용해서 pop한 영역을 초기화(Clear)해주기
		clear((char*)sp->stack + sp->top * dataSize);
		return TRUE;
	}
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - 스택의 모든 데이터 출력(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택관리 구조체의 주소
				  dataSize - 데이터 하나의 크기
				  print - 데이터를 출력할 함수의 시작주소를 저장하는 함수 포인터 변수
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp, size_t dataSize, void(*print)(void*))
{
	int i = sp->top;
	if (sp == NULL) {  /* sp포인터 NULL check*/
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
Function name	: destroyStack -  스택 소멸 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp, size_t dataSize, void(*clear)(void*))
{
	int i = sp->top;
	if (sp == NULL) {  /* sp포인터 NULL check*/
		return;
	}
	while (i != 0) {
		clear((char*)sp->stack + --i * dataSize);
	}
	if (sp->stack != NULL) {	/* statck으로 사용되는 배열 메모리 해제 */
		free(sp->stack);
	}
	sp->stack = NULL;	/* stack 멤버를 NULL pointer로 초기화 */
	sp->size = 0;		/* size와 top멤버를 0으로 초기화 */
	sp->top = 0;
}
