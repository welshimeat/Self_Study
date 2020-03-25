#pragma once
#pragma warning(disable : 4996)
enum { FALSE, TRUE };
typedef struct _node SNode;				/* 구조체 노드 형명재지정 */
struct  _node {							/* 노드 구조체 (자기참조 구조체 사용) */
	int data; 							/* 데이터 영역 : int형 데이터 저장 */
	SNode *next;							/* 포인터 영역 */
};
typedef struct _stack {
	SNode *head;		/* stack으로 사용되는 동적할당 배열을 가리키는 포인터 변수 */
	SNode *tail;		/* 스택의 크기(size) */
}Stack;

int createStack(Stack *);		/* 스택 메모리 할당 및 멤버 초기화 함수 */
int isStackEmpty(const Stack *sPtr);		/* 스택이 완전히 비어있는가 검사 */
int push(Stack *, int);			/* 스택에 데이터 저장하는 함수 */
int pop(Stack *, int *);			/* 스택에서 데이터를 꺼내는 함수 */
void printStack(const Stack*);		/* 스택 내의 모든 데이터를 출력하는 함수 */
void destroyStack(Stack *);			/* 스택 메모리 해제 함수 */
