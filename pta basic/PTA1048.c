/****************************
my faults:λ���ٵ���û�е�λӦ�ò�"0"! 
********************************/ 
#include<stdio.h>
#include<string.h>

int main()
{
	char strnumA[105], strnumB[105], strnum[105];//���ַ��������������� 
	int numA, numB, num, i, n, lenA, lenB;//��strnumA��strnumB��ת��������� 
	int k = 1;//�ж�ż��λ������λ 
	
	scanf("%s%s", strnumA, strnumB);
	lenA = strlen(strnumA);
	lenB = strlen(strnumB);
	//printf("%d %d\n", lenA, lenB);
	for(n = 0; lenA > 0 || lenB > 0; lenA--, lenB--)
	{
		//printf("len : %d %d\n", lenA, lenB);
		if(lenA > 0 && lenB > 0)
		{
			numA = (int)(strnumA[lenA - 1] - '0');
			numB = (int)(strnumB[lenB - 1] - '0');
			//printf("%d %d\n", numA, numB);
		}
		if(lenA <= 0 && lenB > 0)
		{
			numA = 0;
			numB = (int)(strnumB[lenB - 1] - '0');
		//	printf("%d %d\n", numA, numB);
		}
		if(lenA > 0 && lenB <= 0)
		{
			numA = (int)(strnumA[lenA - 1] - '0');
			numB = 0;
			//printf("%d %d\n", numA, numB);
		}
		if((k++) % 2 == 0)
		{
			num = numB - numA;
			if(num < 0)
			num += 10;
			strnum[n++] = (char)(num + '0');//�����ܺ���ַ��Ӹ�λ���strnum�����У�����������strnum�� 
		}
		else
		{
			num = (numA + numB) % 13;
			if(num == 10)
			{
				strnum[n++] = 'J';
			}
			if(num == 11)
			{
				strnum[n++] = 'Q';
			}
			if(num == 12)
			{
				strnum[n++] = 'K';
			}
			if(num < 10)
			{
				strnum[n++] = (char)(num + '0');
			}
		}
	}
	//���ϳ�������ʣ�ಿ�����δ��strnum�С�
	/* 
	if(j >= 0)
	{
		i = j;
	}
	for(; i >= 0; i--)
	{
		if(lenA > lenB)
		{
			numB = 0;
			numA = strnumA[i];
			if((k++) % 2 == 0)
			{
				num = numB - numA;
				if(num < 0)
				num += 10;
				strnum[n++] = (char)(num + '0');
			}
			else
			{
				num = (numA + numB) % 13;
				if(num == 10)
				{
					strnum[n++] = 'J';
				}
				if(num == 11)
				{
					strnum[n++] = 'Q';
				}
				if(num == 12)
				{
					strnum[n++] = 'K';
				}
				if(num < 10)
				{
					strnum[n++] = (char)(num + '0');
				}
			}
		}
		if(lenA < lenB)
		{
			numB = strnumB[i];
			numA = 0;
			if((k++) % 2 == 0)
			{
				num = numB - numA;
				if(num < 0)
				num += 10;
				strnum[n++] = (char)(num + '0');
			}
			else
			{
				num = (numA + numB) % 13;
				if(num == 10)
				{
					strnum[n++] = 'J';
				}
				if(num == 11)
				{
					strnum[n++] = 'Q';
				}
				if(num == 12)
				{
					strnum[n++] = 'K';
				}
				if(num < 10)
				{
					strnum[n++] = (char)(num + '0');
				}
			}
		}
	}*/
	strnum[n] = '\0';
	//�������strnum����Ϊ���ܺ�����֡� 
	for(i = n - 1; i >= 0; i--)
	{
		printf("%c", strnum[i]);
	}
	printf("\n");
	return 0;
} 
