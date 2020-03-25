#pragma once 
enum BOOL { FALSE, TRUE };

typedef struct _queue {
	void *queue;
	int size;
	int front, rear;
}Queue;
BOOL createQueue(Queue * qp, int size, size_t dataSize);		/* ť ���� �� �ʱ�ȭ �Լ� */
BOOL isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
BOOL isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
BOOL enqueue(Queue * qp, void *enqueData, size_t dataSize, void(*memCpy)(void *, void *));	/* ť�� ������ �ϳ��� ���� �� */
BOOL dequeue(Queue * qp, void * dequeData, size_t dataSize, void(*memCpy)(void *, void *), void(*clear)(void*));	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp, size_t dataSize, void(*dataPrint)(void*));			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp, size_t dataSize, void(*clear)(void *));				/* ť �Ҹ� �Լ� */
