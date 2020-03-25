#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "doublyLinkedlist.h"
#include "Person.h"

int menu(const char **mList, size_t menuCnt);
void mInput(List *lp);		/* �Է¸޴� ó�� �Լ� */
void mOutput(List *lp);		/* ��¸޴� ó�� �Լ� */
void mSearch(List *lp);		/* �˻��޴� ó�� �Լ� */
void mDelete(List *lp);		/* �����޴� ó�� �Լ� */
void mSort(List *lp);		/* ���ĸ޴� ó�� �Լ� */
void myflush();				/* �Է� ���� flush �Լ� */
/*----------------------------------------------------------------------------------
  Function name : main
----------------------------------------------------------------------------------*/
int main()
{
	const char *menuList[] = { "�Է��ϱ�","����ϱ�","�˻��ϱ�","�����ϱ�", "�����ϱ�", "��  ��" };
	int menuNum;	/* �޴���ȣ ���� ���� */
	int menuCnt;	/* �޴����� ���� ���� */
	List list;		/* ����Ʈ���� ����ü ���� */
	BOOL bres;

	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	bres = createList(&list);		/* ����ִ� ����Ʈ �ʱ�ȭ */
	if (bres == TRUE)
		printf("@ list ���� ����!\n");
	else
		printf("@ list ���� ����!\n");

	while (1)
	{
		menuNum = menu(menuList, menuCnt);	/* �޴�ȭ���� ���� �޴���ȣ�� �Է� ���� */
		if (menuNum == menuCnt) { break; }
		switch (menuNum)
		{
		case 1: mInput(&list); break;		/* �Է¸޴� ���� */
		case 2: mOutput(&list); break;		/* ��¸޴� ���� */
		case 3: mSearch(&list); break;		/* �˻��޴� ���� */
		case 4: mDelete(&list); break;		/* �����޴� ���� */
		case 5: mSort(&list); break;		/* ���ĸ޴� ���� */
		}
	}
	printf("list���� ������ ����� ���� : %d\n", list.size);

	destroyList(&list, personClear);	/* ����Ʈ���� ��� ������ ���� */

	return 0;
}
/*----------------------------------------------------------------------------------
Function name	: menu
Parameters		: mList - �޴� ��� �迭
				  menuCnt - �޴� ����
Returns			: ����� ������ �޴���ȣ
----------------------------------------------------------------------------------*/
int menu(const char **mList, size_t menuCnt)
{
	size_t menuNum = 0;	/* �������� �ʴ� �޴� ��ȣ ���� */
	size_t i;

	printf("\n\n");
	for (i = 0; i < menuCnt; i++) {	/* �޴� ��� */
		printf("%d. %s\n", i + 1, mList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt) {	/* �޴���ȣ�� ��ȿ���� ���� ���� �ݺ� */
		printf("# �޴� ���� : ");
		scanf("%d", &menuNum);	/* �޴� ��ȣ �Է� */
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: mInput - �Է� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mInput(List *lp)
{
	//int inData;
	Person inData;
	char temp[100];
	int res;  /* scanf()�Լ��� ���� �� ���� */
	BOOL bres;

	printf("\n[ �Է��ϱ� �޴� ]\n\n");

	while (1) {
		printf("# �̸� �Է�(""end"" �Է½� ����) : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { break; }
		inData.name = (char*)malloc(strlen(temp) + 1);
		if (inData.name == NULL) { break; }
		strcpy(inData.name, temp);

		printf("# ���� �Է� : ");
		scanf("%d", &inData.age);

		printf("# ��ȭ��ȣ �Է� : ");
		scanf("%s", inData.phone);

		bres = addLast(lp, &inData, sizeof(Person), personMemCopy);	/* tail ��� �տ� ������ �߰�  */
		if (bres == TRUE)
			printf("@ ������ �߰� ����!\n");
		else
			printf("@ ������ �߰� ����!\n");
		free(inData.name);
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mOutput - ��� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mOutput(List *lp)
{
	displayList(lp, personPrint);
}
/*----------------------------------------------------------------------------------
Function name	: mSearch - �˻� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSearch(List * lp)
{
	Person sData = { NULL, 0, "" };
	char temp[100];
	Node *resp;		/* �˻��� ����� �����ּ� ���� */
	int res;		/* scanf()�Լ��� ���� �� ���� */

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while (1) {
		printf("# �̸� �Է�(""end"" �Է½� ����) : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { break; }
		sData.name = (char*)malloc(strlen(temp) + 1);
		if (sData.name == NULL) { break; }
		strcpy(sData.name, temp);

		resp = searchNode(lp, &sData, personNameCompare);
		if (resp != NULL) {	/* �����͸� ã������ */
			printf("@ �˻� ������ ����!\n");
		}
		else {				/* �����͸� ��ã������ */
			printf("@ �˻� ������ �������� ����!\n");
		}
		free(sData.name);
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mDelete - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mDelete(List * lp)
{
	Person delData;
	int res;		/* scanf()�Լ��� ���� �� ���� */
	BOOL bres;
	Person sData = { NULL, 0, "" };
	char temp[100];

	printf("\n[ �����ϱ� �޴� ]\n\n");
	while (1) {
		printf("# �̸� �Է�(""end"" �Է½� ����) : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { break; }

		delData.name = (char*)malloc(strlen(temp) + 1);
		if (delData.name == NULL) { break; }
		strcpy(delData.name, temp);

		bres = removeNode(lp, &delData, personNameCompare, personClear);
		if (bres == TRUE)
			printf("@ ���� ����!\n");
		else
			printf("@ ���� ����!\n");
		free(delData.name);
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mSort - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSort(List *lp)
{
	sortList(lp, sizeof(Person), personNameCompare, personMemCopy, personClear);
}
/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n') {
		;
	}
}
