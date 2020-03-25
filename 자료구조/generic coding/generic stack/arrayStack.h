#pragma once
enum { FALSE, TRUE };
typedef int BOOL;

typedef struct _stack {
	void *stack;		/* stack���� ���Ǵ� �����Ҵ� �迭�� ����Ű�� ������ ���� */
	int size;		/* ������ ũ��(size) */
	int top;		/* ������ ��,�ⱸ ��ġ���� ���� */
}Stack;

BOOL createStack(Stack *, int, size_t dataSize);		/* ���� �޸� �Ҵ� �� ��� �ʱ�ȭ �Լ� */
BOOL isStackFull(Stack *sPtr);		/* ������ �� ���ִ��� �˻� */
BOOL isStackEmpty(Stack *sPtr);		/* ������ ������ ����ִ°� �˻� */
BOOL push(Stack *, void *, size_t dataSize, void(*memCpy)(void*, void*));			/* ���ÿ� ������ �����ϴ� �Լ� */
BOOL pop(Stack *, void *, size_t dataSize, void(*memCpy)(void*, void*), void(*clear)(void*));			/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*, size_t dataSize, void (*print)(void*));		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *, size_t dataSize, void (*clear)(void*));			/* ���� �޸� ���� �Լ� */
