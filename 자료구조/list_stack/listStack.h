#pragma once
#pragma warning(disable : 4996)
enum { FALSE, TRUE };
typedef struct _node SNode;				/* ����ü ��� ���������� */
struct  _node {							/* ��� ����ü (�ڱ����� ����ü ���) */
	int data; 							/* ������ ���� : int�� ������ ���� */
	SNode *next;							/* ������ ���� */
};
typedef struct _stack {
	SNode *head;		/* stack���� ���Ǵ� �����Ҵ� �迭�� ����Ű�� ������ ���� */
	SNode *tail;		/* ������ ũ��(size) */
}Stack;

int createStack(Stack *);		/* ���� �޸� �Ҵ� �� ��� �ʱ�ȭ �Լ� */
int isStackEmpty(const Stack *sPtr);		/* ������ ������ ����ִ°� �˻� */
int push(Stack *, int);			/* ���ÿ� ������ �����ϴ� �Լ� */
int pop(Stack *, int *);			/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*);		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *);			/* ���� �޸� ���� �Լ� */
