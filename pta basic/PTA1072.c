#include<stdio.h>

int check(int num, int *arr, int len);

int main()
{
	int stunum, kindnum, i, j, kind[6], flag = 1;
	/*stunum��ѧ��������kindnum����ֹЯ����Ʒ������kind�������ֹ��Ʒ���*/ 
	char name[6];//���ѧ������ 
	int thingnum, thing, sumstu = 0, sumthing = 0, temp;
	/*thingnum��ѧ��Я����Ʒ������thing����Я����Ʒ��ţ�sumstu��Я����ֹ��Ʒ��ѧ��������
	��sumthing����Я���Ľ�ֹ��Ʒ����*/ 
	scanf("%d %d", &stunum, &kindnum);
	//�����ֹ��Ʒ��� 
	for(i = 0; i < kindnum; i++)
	{
		scanf("%d", &kind[i]);
	}
	for(i = 0; i < stunum; i++)
	{
		getchar();
		flag = 1;
		temp = 1;
		//����ÿ��ѧ�������ֺ���Я������Ʒ��������Ʒ��� 
		scanf("%s %d", name, &thingnum);
		for(j = 0; j < thingnum; j++)
		{
			scanf("%d", &thing);
			//�жϸñ����Ʒ�Ƿ�����ֹ��Ʒ 
			if(check(thing, kind, kindnum) == 0) 
			{ 
				if(temp)
				{
					sumstu++;
					temp = 0;
				}
				sumthing++;
				if(flag)
				{
					printf("%s: %04d", name, thing);
					flag = 0;
				}
				else
				{
					printf(" %04d", thing);
				}
			}
		}
		if(temp == 0) 
		printf("\n");
	}
	printf("%d %d\n", sumstu, sumthing);
	return 0;
}
int check(int num, int *arr, int len)
{
	int i, flag = 1;
	
	for(i = 0; i < len; i++)
	{
		if(num == arr[i])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
