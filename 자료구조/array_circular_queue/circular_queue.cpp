#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"

/*--------------------------------------------------------------------------------------
Function name	: createQueue - 원형큐 생성 및 초기화 함수
Parameters		: qp - 큐 구조체의 주소
				  size - 큐의 크기
Returns			: 생성 성공하면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int createQueue(Queue * qp, int size)
{
	if (qp == NULL) {  /* qp 포인터 NULL check*/
		return FALSE;
	}
	qp->queue = (int*)malloc(sizeof(int)*size);
	if(qp->queue == NULL)
		return FALSE;
	qp->front = qp->rear = 0;
	return TRUE;
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
	if(qp->front == qp->rear)
		return TRUE;
	else return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - 큐가 꽉차있는가 검사
Parameters		: qp - 큐 구조체의 주소
Returns			: 꽉차 있으면 TRUE 리턴, 아니면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int isQueueFull(const Queue *qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}
	if((qp->rear+1)%qp->size == qp->front)
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
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}
	if(isQueueFull(qp) == TRUE)
		return FALSE;
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear+1)%qp->size;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - 큐에서 데이터 하나를 꺼냄
Parameters		: qp - 큐 구조체의 주소
				  dequeData - 꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qp, int * dequeData)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return FALSE;
	}
	if(isQueueEmpty(qp) == TRUE)
		return FALSE;
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front+1)%qp->size;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - 큐 내의 모든 데이터를 출력 함
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return;
	}
	/* queue내의 모든 데이터 출력 (dequeue 하면 출력되는 순서로 출력) */
	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("%5d\n", qp->queue[i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - 큐 소멸 함수
Parameters		: qp - 큐 구조체의 주소
Returns			: 없음
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp포인터 NULL check*/
		return;
	}
	if(qp->queue != NULL){
		free(qp->queue);
		qp->queue = NULL;
		qp->size = qp->front = qp->rear = 0;
	}
	return;
}
