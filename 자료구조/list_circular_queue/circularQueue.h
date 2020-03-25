#pragma once
#pragma warning (disable : 4996)
enum { FALSE, TRUE };
typedef struct _node Node;
struct _node {
	int data;
	Node *next;
};
typedef struct _queue {
	Node *head;
	Node *tail;
}Queue;

int createQueue(Queue * qp);		/* ť ���� �� �ʱ�ȭ �Լ� */
int isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
int enqueue(Queue * qp, int enqueData);	/* ť�� ������ �ϳ��� ���� �� */
int dequeue(Queue * qp, int * dequeData);	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp);			/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp);				/* ť �Ҹ� �Լ� */
