#pragma once
#include "doublyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if (lp == NULL) {  /* lp������ NULL check */
		return FALSE;
	}
	lp->head = (Node *)malloc(sizeof(Node));	/* head node ���� */
	if (lp->head == NULL) {
		return FALSE;
	}
	lp->tail = (Node *)malloc(sizeof(Node));	/* tail node ���� */
	if (lp->tail == NULL) {
		free(lp->head);
		return FALSE;
	}

	lp->head->next = lp->tail; /* head node�� tail node ���� */
	lp->tail->next = lp->tail; /* tail node�� next�� �ڱ� �ڽ��� ����Ű���� ���� */
	lp->head->prev = lp->head; /* head node�� prev�� �ڱ� �ڽ��� ����Ű���� ����*/
	lp->tail->prev = lp->head; /* tail node�� prev�� head�� ����Ű���� ����*/
	lp->size = 0;	/* ���� ����Ʈ ũ�� 0���� �ʱ�ȭ */

	return TRUE;
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, void *data, size_t dataSize, void(*memCpy)(void *, void *))
{
	Node *newp;

	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	newp = (Node *)calloc(1, sizeof(Node) + dataSize); /* �� ��� ���� */
	if (newp != NULL) {				/* �� ��� ���� ���� �� ó�� */
		memCpy(newp + 1, data);		/* �� ��忡 data ���� */
		newp->next = lp->head->next; /* �� ����� next ���� */
		lp->head->next = newp;	/* head ndoe �ڿ� �� ��� ���� */
		newp->prev = lp->head;
		newp->next->prev = newp;
		++lp->size;					/* ����Ʈ size ���� */
		return TRUE;
	}
	else {							/* �� ��� ���� ���� �� ó�� */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void *data, size_t dataSize, void (*memCpy)(void *, void *))
{
	Node *newp;	/* �� ��� �ּ������ ������ */
	
	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}

	newp = (Node *)calloc(1, sizeof(Node) + dataSize);	/* �� ��� ���� */
	if (newp != NULL) {	/*  �� ��� ���� ���� �� ó�� */
		//memCpy((char*)newp + 8, data);	/* �� ��忡 data ���� */
		memCpy(newp + 1, data);

		newp->next = lp->tail;	/* �� ����� next ���� */
		lp->tail->prev->next = newp;
		newp->prev = lp->tail->prev;
		lp->tail->prev = newp;
		++lp->size;	/* ����Ʈ size ���� */
		return TRUE;
	}
	else {	/* �� ��� ���� ���� �� ó�� */
		return FALSE;
	}
}

/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp, void(*dataPrint)(void *))
{
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	curp = lp->head->next;  /* data �ִ� ù��带 curp�� ����Ű�� �� */

	/* ����Ʈ�� ������ ������ curp�� �ű�鼭 data���� ����ϱ� */
	while (curp != lp->tail) {
		//printf("%8d\n", curp->data);
		dataPrint(curp + 1);
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
Node * searchNode(List *lp, void *data, int (*compare)(void *, void *))
{
	Node *curp;

	if (lp == NULL) { /* lp������ NULL check */
		return NULL;
	}

	curp = lp->head->next;/* dataù��带 curp�� ����Ű�� �� */
	/* ����Ʈ�� ������ ������ ������ curp�� �ű�鼭 �˻��ϱ� */
	while (curp != lp->tail) {
		if (compare(curp+1, data) == 0) {
			return curp;	/* ã�� ����� �ּ� ���� */
		}
		else {
			curp = curp->next;
		}
	}

	return NULL;	/* ��ã���� NULL pointer ���� */
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void *data, int (*compare)(void *, void *), void (*clear)(void*))
{
	Node *delp;
	if (lp == NULL) { /* lp������ NULL check */
		return FALSE;
	}
	delp = searchNode(lp, data, compare);  /* ������ node�� �˻� �� */
	if (delp != NULL) { /* ������ ��带 ã������ �����ϱ� */

		delp->prev->next = delp->next; /* ������ ����� �� ���� ������ ����� �� ��带 ����*/
		delp->next->prev = delp->prev;
		clear(delp + 1); // ���� ��� �����ϱ� ���� ������ ������ �ʱ�ȭ ��Ŵ
		free(delp);	/* ��� ���� */
		--lp->size;	/* ����Ʈ size ���� */
		return TRUE;
	}
	else {	/* ������ ����� ��ã������ ���� ���� */
		return FALSE;
	}
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List* lp, size_t dataSize, int (*compare)(void*, void*), void (*memCpy)(void*, void*), void (*clear)(void*))
{
	Node *curp;
	Node *nextp;
	void *temp;
	if (lp == NULL) { /* lp������ NULL check */
		return;
	}

	temp = calloc(1,dataSize);
	if (temp == NULL) {
		return;
	}
	curp = lp->head->next;
	while (curp->next != lp->tail) {
		nextp = curp->next;
		while (nextp != lp->tail) {
			if (compare(curp+1, nextp+1)>0) {
				memCpy(temp, curp + 1);
				memCpy(curp + 1, nextp + 1);
				memCpy(nextp + 1, temp);
			}
			nextp = nextp->next;
		}
		curp = curp->next;
	}
	free(temp);
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp, void (*clear)(void *))
{
	Node *curp;
	Node *nextp;
	if (lp == NULL) { /* lp������ NULL check */
		return;
	}
	curp = lp->head->next;
	while (curp != lp->tail) {
		nextp = curp->next;
		clear(curp + 1);
		free(curp);
		curp = nextp;
	}
	free(lp->head);
	free(lp->tail);

	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}

