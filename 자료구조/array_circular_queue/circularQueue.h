#pragma once 
#pragma warning (disable : 4996)
enum { FALSE, TRUE };

typedef struct _queue {
	int *queue;
	int size;
	int front, rear;
}Queue;

int createQueue(Queue * qp, int size);		/* ť ���� �� �ʱ�ȭ �Լ� */
int isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
int isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
int enqueue(Queue * qp, int enqueData);	/* ť�� ������ �ϳ��� ���� �� */
int dequeue(Queue * qp, int * dequeData);	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp);			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp);				/* ť �Ҹ� �Լ� */
