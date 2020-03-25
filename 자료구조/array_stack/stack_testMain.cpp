#include "arrayStack.h"
#include <stdio.h>

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

	createStack(&stk, 5); /* ���� �ʱ�ȭ*/
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
	destroyStack(&stk);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - ���ÿ� �����͸� �ݺ������� �Է���
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mInput(Stack *sp)
{
	int data;

	while (1) {
		printf("Push�� �����������͸� �Է��Ͻÿ�(���ڳ� �Է� �� ����) : ");
		if (scanf("%d", &data) != 1) { /* ���ڰ� �ԷµǸ� while���� ��������*/
			myflush();
			break;
		}
		if (push(sp, data) == FALSE)
			printf("push ����!\n");
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
	int popData;	/* pop�� �����͸� ������ ����*/
	int res;		/* pop()�Լ��� ���ϰ��� ������ ����*/

	printf("Stack���� �����͸� pop�� Ƚ���� �Է��Ͻÿ�: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = pop(sp, &popData);
		if (res == 1)  /* ���������� pop �۾�������������*/
		{
			printf("pop ������: %5d\n", popData);
		}
		else
			printf("pop ����!\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: mOutput - ������ ��� ������ ��� �ϱ�
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mOutput(Stack *sp)
{
	printStack(sp);
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
	for (i = 0; i<menuCnt; i++)
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
