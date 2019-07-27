/*************************** 
�����ܣ���������������������г��� 
*****************************/
#include<stdio.h>
#include<string.h>

char str1[100], str2[100];
int data[100][100];

int max(int num1, int num2)
{
	int Max;
	
	if(num1 > num2)
	{
		Max = num1;
	}
	else
	{
		Max = num2;
	}
	return Max;
}

int maxlen(int len1, int len2)
{	
	if(len1 == 0 || len2 == 0)
	{
		data[len1][len2] = 0;
	}
	if(data[len1][len2] != -1)
	{
		return data[len1][len2];
	}
	//���ƹ�ʽ 
	if(str1[len1 - 1] == str2[len2 - 1])
	{
		data[len1][len2] = maxlen(len1 - 1, len2 - 1) + 1;
	}
	else
	{
		data[len1][len2] = max(maxlen(len1, len2 - 1), maxlen(len1 - 1, len2));
	}
	return data[len1][len2];
}

int main()
{
	memset(data, -1, sizeof(data));
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	printf("��󹫹������г���Ϊ��%d", maxlen(strlen(str1), strlen(str2))); 
	return 0;
}
