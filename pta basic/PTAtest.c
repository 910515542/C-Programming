/*************************
��������ָ������� ÿ������С[0,9];
��һ��������ִ�������5�����֣�
�ڶ���������ִ�������3������
������������ִ�������1�Ĵ��� 
*************************/
#include<stdio.h>

void output(int *count);

int main()
{
	int count[10] = {0}, i, n, temp;
	
	printf("������Ҫ��������ָ�����");
	scanf("%d", &n);
	printf("������%d�����֣�", n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		count[temp]++;
	}
	output(count);
	return 0;
}

void output(int *count)
{
	int i;
	
	printf("������5�����ϵ������У� ");
	for(i = 0; i < 10; i++)
	{
		if(count[i] > 5)
		{
			printf("%d ", i);
		}
	}
	printf("\n"); 
	printf("������3�����ϵ������У�");
	for(i = 0; i < 10; i++)
	{
		if(count[i] > 3)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("ֻ����һ�ε������У�");
	for(i = 0; i < 10; i++)
	{
		if(count[i] == 1)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}
