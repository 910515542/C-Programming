/**************
my faults:����strcmp�� ���ó���strcpy��
******************/ 
#include<stdio.h>
#include<string.h>

struct _name{
	char name[21];
} Name[1001], jiang[1001];

int check(char *str1, struct _name *str2, int len); 

int main()
{
	int m, n, s, i, j, count = 0;
	
	scanf("%d %d %d", &m, &n, &s);//ת���������������������ʼ��� 
	for(i = 0; i < m; i++)
	{
		scanf("%s", Name[i].name);
		jiang[i].name[0] = 0;
	}
	for(i = s; i <= m; i += n)
	{
		while(check(Name[i - 1].name, jiang, count) && i <= m)
		{
			i++;
		}
		if(i != m + 1)//��������ֲ�ȫ���Ѿ����˽��� 
		{
			printf("%s\n", Name[i - 1].name);
			//�������н������ִ����н������� 
			jiang[count++] = Name[i - 1];
		}
	}
	
	if(count == 0)//�н�����Ϊ�� 
	{
		printf("Keep going...\n");
	}
	return 0;
}

int check(char *str1, struct _name *str2, int len)
{
	int i, flag = 0;
	
	for(i = 0; i < len; i++)
	{
		if(strcmp(str1, str2[i].name) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}
