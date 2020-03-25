#pragma warning (disable : 4996)
#include "arrayStack.h"
#include <stdio.h>
#include "Person.h"
#include <stdlib.h>
#include <string.h>

int menu(const char **mList, size_t menuCnt);	/* �޴� ��� �� �޴���ȣ �Է� �Լ� */
void mInput(Stack *sp);			/* �Է¸޴� ó�� �Լ� */
void myDelete(Stack *sp);		/* �����޴� ó�� �Լ� */
void mOutput(Stack *sp);		/* ��¸޴� ó�� �Լ� */
void myflush();					/* �Է� ���� flush �Լ� */
/*----------------------------------------------------------------------------------
Function name	: main
----------------------------------------------------------------------------------*/
int main()
{
	Stack stk;		/* ���û���*/
	const char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" }; /* �޴� ����Ʈ*/
	int menuCnt;	/* �޴����� ���庯��*/
	int menuNum;	/* �޴���ȣ ���庯��*/

	createStack(&stk, 5, sizeof(Person)); /* ���� �ʱ�ȭ*/
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  /* �޴� ���� ����ϱ�*/

	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt)  /* ����޴� ���� �� �ݺ��� Ż���ϱ�*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: mInput(&stk);  break;
		case 2: myDelete(&stk); break;
		case 3: mOutput(&stk); /* stack���� ��� ������ ����ϱ�*/
		}
	}
	destroyStack(&stk, sizeof(Person), personClear);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - ���ÿ� �����͸� �ݺ������� �Է���
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mInput(Stack *sp)
{
	//int data;
	Person data = { NULL, 0, "" }; // �Է¹��� �����͸� ������ ����ü ����
	char temp[100]; // �����Է� �ӽ� �迭
	while (1) {
		printf("Push�� ������ �Է�(""end"" �Է� �� ����) : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") == 0) { break; }
		data.name = (char*)malloc(strlen(temp) + 1); // �޸� �Ҵ�(�޸� ���� ����)
		if (data.name == NULL)
			break;
		strcpy(data.name, temp);
		printf("Push�� ���� �Է� : ");
		scanf("%d", &data.age);
		printf("Push�� ��ȭ��ȣ �Է� : ");
		scanf("%s", data.phone);
		if (push(sp, &data, sizeof(Person), personMemCopy) == FALSE)
			printf("push ����!\n");
		free(data.name); // �޸� ����
	}
}
/*--------------------------------------------------------------------------------------
Function name	: myDelete() - ������ �����͸� �ݺ������� ����
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sp)
{
	int i;
	int cnt;		/* pop�� Ƚ���� �Է¹޾� ������ ����*/
	//int popData;	/* pop�� �����͸� ������ ����*/
	Person popData = { NULL, 0, "" }; /* pop�� �����͸� ������ ����*/
	int res;		/* pop()�Լ��� ���ϰ��� ������ ����*/

	printf("Stack���� �����͸� pop�� Ƚ���� �Է��Ͻÿ�: ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		res = pop(sp, &popData, sizeof(Person), personMemCopy, personClear);
		if (res == 1)  /* ���������� pop �۾�������������*/
		{
			//printf("pop ������: %5d\n", popData);
			personPrint(&popData);
		}
		else
			printf("pop ����!\n");
	}
	//free(popData.name);
	//popData.name = NULL;
	personClear(&popData);
}
/*--------------------------------------------------------------------------------------
Function name	: mOutput - ������ ��� ������ ��� �ϱ�
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mOutput(Stack *sp)
{
	printStack(sp, sizeof(Person), personPrint);
}
/*--------------------------------------------------------------------------------------
Function name	: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է¹޾� ������
Parameters		: menuLIst - �޴������ ���ڿ�
				  menuCnt  - �޴�����
Returns			: ���õȸ޴���ȣ
--------------------------------------------------------------------------------------*/
int menu(const char **menuList, size_t menuCnt)
{
	size_t i;
	size_t menuNum = 0;	/* �Էµ� �޴���ȣ ���� ����*/
	int res;			/* scanf()�Լ��� ���ϰ� ���� ����*/
	for (i = 0; i < menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* �޴���ȣ �������� ��ȣ�� �Էµɶ� ���� �ݺ�*/
	{
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%u", &menuNum);
		if (res != 1)  /* ������ �Էµ��� �ʾ�����*/
		{
			myflush();  /* �Է¹��� ����*/
			continue;
		}
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}
