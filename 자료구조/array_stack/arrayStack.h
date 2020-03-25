#pragma once
#pragma warning(disable : 4996)
enum { FALSE, TRUE };

typedef struct _stack {
	int *stack;		/* stack���� ���Ǵ� �����Ҵ� �迭�� ����Ű�� ������ ���� */
	int size;		/* ������ ũ��(size) */
	int top;		/* ������ ��,�ⱸ ��ġ���� ���� */
}Stack;

int createStack(Stack *, int);		/* ���� �޸� �Ҵ� �� ��� �ʱ�ȭ �Լ� */
int isStackFull(Stack *sPtr);		/* ������ �� ���ִ��� �˻� */
int isStackEmpty(Stack *sPtr);		/* ������ ������ ����ִ°� �˻� */
int push(Stack *, int);			/* ���ÿ� ������ �����ϴ� �Լ� */
int pop(Stack *, int *);			/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*);		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *);			/* ���� �޸� ���� �Լ� */
