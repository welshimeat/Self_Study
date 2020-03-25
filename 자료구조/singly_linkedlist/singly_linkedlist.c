#include "singlyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
int createList(List *lp)
{
	if (lp == NULL) { /* lp������ NULL check */
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
	return TRUE; // return ���� �������ּ���.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
int addFirst(List *lp, int data)
{
	Node *newp;

	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}
	newp = (Node*)malloc(sizeof(Node));
	if(newp == NULL)
		return FALSE;
	newp->next = lp->head->next;
	lp->head->next = newp;
	newp->data = data;
	lp->size++;
	return TRUE; // return ���� �������ּ���.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
int addLast(List *lp, int data)
{
	Node *newp;	/* �� ��� �ּ������ ������ */
	Node *btp;	/* tail node �ٷ� �� ��带 ����Ű�� ������ */
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
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
	return TRUE; // return ���� �������ּ���.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
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
Function name	: searchNode - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
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
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
int removeNode(List *lp, int data)
{
	Node *delp;
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
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

	return FALSE; // return ���� �������ּ���.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node *curp;
	Node *nextp;
	int temp;

	if (lp == NULL) { /* lp������ NULL check */
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
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	Node *curp;
	Node *nextp;
	if (lp == NULL) { /* lp������ NULL check */
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
