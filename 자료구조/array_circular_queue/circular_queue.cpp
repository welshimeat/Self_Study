#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ����ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int createQueue(Queue * qp, int size)
{
	if (qp == NULL) {  /* qp ������ NULL check*/
		return FALSE;
	}
	qp->queue = (int*)malloc(sizeof(int)*size);
	if(qp->queue == NULL)
		return FALSE;
	qp->front = qp->rear = 0;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - ť�� ����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}
	if(qp->front == qp->rear)
		return TRUE;
	else return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - ť�� �����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� ������ TRUE ����, �ƴϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueFull(const Queue *qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}
	if((qp->rear+1)%qp->size == qp->front)
		return TRUE;
	else return FALSE;
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
			  	  enqueData - ť�� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int enqueue(Queue * qp, int enqueData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}
	if(isQueueFull(qp) == TRUE)
		return FALSE;
	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear+1)%qp->size;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qp, int * dequeData)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}
	if(isQueueEmpty(qp) == TRUE)
		return FALSE;
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front+1)%qp->size;
	return TRUE;
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}
	/* queue���� ��� ������ ��� (dequeue �ϸ� ��µǴ� ������ ���) */
	for (int i = qp->front; i != qp->rear; i = (i + 1) % qp->size)
	{
		printf("%5d\n", qp->queue[i]);
	}
	printf("\n");
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}
	if(qp->queue != NULL){
		free(qp->queue);
		qp->queue = NULL;
		qp->size = qp->front = qp->rear = 0;
	}
	return;
}
