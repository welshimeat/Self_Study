#include "singlyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int createList(List *lp)
{
	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}
	lp->head = (Node*)malloc(sizeof(Node));
	if(lp->head == NULL)
		return FALSE;
	lp->tail = (Node*)malloc(sizeof(Node));
	if(lp->tail == NULL){
		free(lp->head);
		return FALSE;
	}
	lp->tail->next = lp->tail;
	lp->head->next = lp->tail;
	lp->size = 0;
	return TRUE; // return 값은 수정해주세요.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int addFirst(List *lp, int data)
{
	Node *newp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}
	newp = (Node*)malloc(sizeof(Node));
	if(newp == NULL)
		return FALSE;
	newp->next = lp->head->next;
	lp->head->next = newp;
	newp->data = data;
	lp->size++;
	return TRUE; // return 값은 수정해주세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int addLast(List *lp, int data)
{
	Node *newp;	/* 새 노드 주소저장용 포인터 */
	Node *btp;	/* tail node 바로 앞 노드를 가리키는 포인터 */
	Node *curp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}
	newp = (Node*)malloc(sizeof(Node));
	if(newp == NULL)
		return FALSE;
	curp = lp->head;
	while(curp != lp->tail){
			btp = curp;
			curp = curp->next;
	}
	newp->next = lp->tail;
	newp->data = data;
	btp->next = newp;
	lp->size++;
	return TRUE; // return 값은 수정해주세요.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *curp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return;
	}
	curp = lp->head->next;
	while(curp != lp->tail){
		printf("%5d", curp->data);
		curp = curp->next;
	}
	printf("\n");
	return;
}

/*----------------------------------------------------------------------------------
Function name	: searchNode - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	Node *curp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return NULL;
	}
	curp = lp->head->next;
	while(curp != lp->tail){
		if(curp->data == data)
			return curp;
		curp = curp->next;
	}
	return NULL;
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
int removeNode(List *lp, int data)
{
	Node *delp;
	Node *curp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return FALSE;
	}
	delp = lp->head;
	while(delp != lp->tail){
		curp = delp;
		delp = delp->next;
		if(delp->data == data){
			curp->next = delp->next;
			free(delp);
			lp->size--;
			return TRUE;
		}
	}

	return FALSE; // return 값은 수정해주세요.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node *curp;
	Node *nextp;
	int temp;

	if (lp == NULL) { /* lp포인터 NULL check */
		return;
	}
	curp = lp->head->next;
	nextp = curp->next;
	while(curp != lp->tail){
		while(nextp != lp->tail){
			if(curp->data > nextp->data){
				temp = nextp->data;
				nextp->data = curp->data;
				curp->data = temp;
			}
			nextp = nextp->next;
		}
		curp = curp->next;
		nextp = curp->next;
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	Node *curp;
	Node *nextp;
	if (lp == NULL) { /* lp포인터 NULL check */
		return;
	}
	curp = lp->head->next;
	while(curp != lp->tail){
		nextp = curp->next;
		free(curp);
		curp = nextp;
	}
	free(lp->head);
	free(lp->tail);
	lp->head = NULL;
	lp->tail = NULL;
	lp->size = 0;

	return;
}
