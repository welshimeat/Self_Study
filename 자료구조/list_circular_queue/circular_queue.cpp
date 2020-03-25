#include <stdio.h>
#include <stdlib.h>
#include "circularQueue.h"

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ����ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int createQueue(Queue * qp)
{
	if (qp == NULL) {  /* qp ������ NULL check*/
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
	return TRUE;  // ���ϰ��� �����ϼ���.
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
	if(qp->head->next == qp->tail)
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
	Node *curp, *newp;
	if (qp == NULL) {  /* qp������ NULL check*/
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
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int dequeue(Queue * qp, int * dequeData)
{
	Node *curp;
	if (qp == NULL) {  /* qp������ NULL check*/
		return FALSE;
	}
	if(isQueueEmpty(qp) == TRUE)
		return FALSE;
	*dequeData = qp->head->next->data;
	curp = qp->head->next;
	qp->head->next = qp->head->next->next;
	free(curp);
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	Node *curp;
	if (qp == NULL) {  /* qp������ NULL check*/
		return;
	}
	if(isQueueEmpty(qp) == TRUE){
		printf("Queue�� ������ϴ�!!\n");
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
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	Node *curp, *btp;
	if (qp == NULL) {  /* qp������ NULL check*/
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
