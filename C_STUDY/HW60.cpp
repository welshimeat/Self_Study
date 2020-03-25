#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* �ֹε�Ϲ�ȣ ����*/
int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear (int year);

int main()
{
    /* �׽�Ʈ�� �ֹε�Ϲ�ȣ ���� �迭*/
    char resident_number[][20]={"0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
"8806311069417","8807311069418" };
    int i, count;
    /* �˻��� �ֹε�Ϲ�ȣ�� ���� ���*/
    count = sizeof(resident_number)/ sizeof(resident_number[0]);
    for(i=0; i<count; i++) /* �ֹε�Ϲ�ȣ ��ȿ�� �˻縦 �ݺ������� ���� ��*/
    {
	if(availabilityCheck(resident_number[i]) == TRUE)
	{
	printf("(+) �ֹι�ȣ%s��(��) ��ȿ�� ��ȣ�Դϴ�.\n", resident_number[i]);
	}
	else
	{
	    printf("(-) �ֹι�ȣ%s��(��) ��ȿ���� ���� ��ȣ�Դϴ�.\n", resident_number[i]);
	}
    }
	return 0;
}
/*----------------------------------------------------------------
  availabilityCheck()�Լ�: �ֹε�Ϲ�ȣ ��ȿ�� �˻� �Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: ��ȿ�ϸ�TRUE, ��ȿ���� ������FALSE ����
------------------------------------------------------------------*/
int availabilityCheck(char *resident_number)
{
  if(checkLengthCharacter(resident_number) && checkDate(resident_number) && checkGender(resident_number) && checkIdentification(resident_number))
    return TRUE;
  else return FALSE;
}

/*-------------------------------------------------------------------------
  checkLengthCharacter()�Լ�: �ֹε�Ϲ�ȣ ���� �� ���� ��ȿ���˻� �Լ�
  ��������: �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: �ֹε�Ϲ�ȣ�� ���̰� �°� ���ڹ��ڷθ� �����Ǿ� ������TRUE,
           ���̰� ª�ų� ���, ���� ���ڰ� �ƴ� ���ڰ� ���� ������FALSE ����
--------------------------------------------------------------------------*/
int checkLengthCharacter(char *resident_number)
{
  if(strlen(resident_number) != RESIDENT_NUMBER_LENGTH)
    return FALSE;
  else{
    for(int i=0; i<RESIDENT_NUMBER_LENGTH; i++){
      if(resident_number[i] < '0' || resident_number[i] > '9')
        return FALSE;
      }
  }
  return TRUE;
}
/*----------------------------------------------------------------
  checkDate()�Լ�: ù6�ڸ�(��,��,��)�� ��ȿ�� �˻� �Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: ��ȿ�� ��¥�̸�TRUE, ��ȿ���� ���� ��¥�̸�FALSE ����
------------------------------------------------------------------*/
int checkDate(char *resident_number)
{
  int year, month, day, month2day[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  year = resident_number[1]-'0' + 10*(resident_number[0]-'0');
  month = resident_number[3]-'0' + 10*(resident_number[2]-'0');
  day = resident_number[5]-'0' + 10*(resident_number[4]-'0');
  if(resident_number[6]-'0'<3)
    year += 1000;
  else
    year += 2000;
  if(checkYear(year) == FALSE)
    month2day[1] = 28;

  if(month<1 || month>12)
    return FALSE;
  else if(day<1 || day>month2day[month-1])
    return FALSE;
  else return TRUE;
}
/*----------------------------------------------------------------------
  checkGender()�Լ�: 7��° �ڸ��� �����ĺ���ȣ ��ȿ�� �˻��Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: �����ĺ���ȣ��'1'~'4'�̸�TRUE, �� �� ���� �����̸�FALSE ����
-----------------------------------------------------------------------*/
int checkGender(char *resident_number)
{
  if(resident_number[6]-'0' < 1 || resident_number[6]-'0' > 4){
    return FALSE;
  }
  else return TRUE;
}
/*------------------------------------------------------------------------
  checkIdentification()�Լ�: �ֹε�Ϲ�ȣ ���ڸ�(�ν���) ��ȿ�� �˻� �Լ�
  ��������: ��ȿ�� �˻��� �ֹε�Ϲ�ȣ(���ڿ�)
  ���ϰ�: ��ȿ�� �ν����̸�TRUE, ��ȿ���� ���� �ν����̸� FALSE ����
-------------------------------------------------------------------------*/
int checkIdentification(char *resident_number)
{
  int sum=0;
  for(int i=0; i<RESIDENT_NUMBER_LENGTH-1; i++)
    sum += resident_number[i] - '0';
  if(sum%10 != resident_number[RESIDENT_NUMBER_LENGTH-1] - '0'){
    return FALSE;
  }
  else return TRUE;
}
/*----------------------------------------------------------------
 checkYear ()�Լ�: �⵵�� ��,��� ���� �˻�
  ��������: ��,��� �˻��� �⵵
  ���ϰ�: �����̸� TRUE, ����̸�FALSE ����
------------------------------------------------------------------*/
int checkYear(int year){
  if(year%4 == 0){
    if(year%100 == 0){
      if(year%400 == 0)
        return TRUE;
      else return FALSE;
    }
    else return TRUE;
  }
  else return FALSE;
}
