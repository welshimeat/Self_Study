#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"

/*--------------------------------------------------------------------------------------
Function name	: createQueue - 원형큐 생성 및 초기화 함수
Parameters		: qp - 큐 구조체의 주소
				  size - 큐의 크기
Returns			: 생성 성공하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int createQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp 포인터 NULL check*/
		return FALSE;
	}
	qp->head = (Node*)malloc(sizeof(Node));
	if(qp->head == NULL)
		return FALSE;
	qp->tail = (Node*)malloc(sizeof(Node));
	if(qp->tail == NULL){
		free(qp->head);
		return FALSE;
	}
	qp->head->next = qp->tail;
	qp->tail->next = qp->tail;
	return TRUE;  // 리턴값을 수정하세요.
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - 큐가 비어있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns			: 완전히 비어있으면 TRUE 리턴, 비어있지 않으면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}
	if(qp->head->next == qp->tail)
		return TRUE;
	else return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - 큐에 데이터 하나를 저장함
Parameters		: qp - 큐 구조체의 주소
			  	  enqueData - 큐에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qp, int enqueData)
{
	Node *curp, *newp;
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}
	newp = (Node*)malloc(sizeof(Node));
	if(newp == NULL)
		return FALSE;
	curp = qp->head;
	while(curp->next != qp->tail){
		curp = curp->next;
	}
	curp->next = newp;
	newp->next = qp->tail;
	newp->data = enqueData;
	return TRUE;  // 리턴값을 수정하세요.
}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - 큐에서 데이터 하나를 꺼냄
Parameters		: qp - 큐 구조체의 주소
				  dequeData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qp, int * dequeData)
{
	Node *curp;
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}
	if(isQueueEmpty(qp) == TRUE)
		return FALSE;
	*dequeData = qp->head->next->data;
	curp = qp->head->next;
	qp->head->next = qp->head->next->next;
	free(curp);
	return TRUE;  // 리턴값을 수정하세요.
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - 큐 내의 모든 데이터를 출력 함
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	Node *curp;
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return;
	}
	if(isQueueEmpty(qp) == TRUE){
		printf("Queue가 비었습니다!!\n");
		return;
	}
	curp = qp->head->next;
	while(curp != qp->tail){
		printf("%5d\n", curp->data);
		curp = curp->next;
	}
		printf("\n\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - 큐 소멸 함수
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	Node *curp, *btp;
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return;
	}
	curp = qp->head->next;
	while(curp != qp->tail){
		btp = curp->next;
		free(curp);
		curp = btp;
	}
	free(qp->head);
	free(qp->tail);
	qp->head = qp->tail = NULL;
	return;
}
