/******************************
my faults: 
*****************************/ 
#include<stdio.h>
//#include<stdlib.h>

int flag(char a, char b);//��AӮ����1��ƽ�ַ���0��BӮ����-1 
char find(int a, int b, int c);//����Ϊ��������Ӯ�Ĵ�������B,C,J�������ʤ���Ĵ���������ʤ������������ƣ�������ͬ����ĸ˳�򷵻� 

/*struct _arr{
	char A;
	char B;
} arr[100000];*/

int main()
{
	int N = 0, i = 0, j = 0, symbol;//NΪ�Ծֳ��� 
	int countA = 0, countB = 0, countAB = 0;//���A��B��ʤ����ƽ�ִ��� 
	int countA_C = 0, countA_J = 0, countA_B = 0;// ���A����������ʤ������ 
	int countB_C = 0, countB_J = 0, countB_B = 0;//���B����������ʤ������ 
	char chA, chB;//���A,B��ÿ�ֵ����� 
	
	scanf("%d", &N);
	for(i = 0; i < N; i++)
	{
		fflush(stdin);
		scanf("%c %c", &chA, &chB);
		symbol = flag(chA, chB);
		if( symbol == 1 )
		{
			countA++; 
			if(chA == 'C')
			{
				countA_C++;
			}
			if(chA == 'B')
			{
				countA_B++;
			}
			if(chA == 'J')
			{
				countA_J++;
			}
		}
		else
		{
			if( symbol == 0 )
			{
				countAB++;
			}
			else
			{
				countB++;
				if(chB == 'C')
				{
					countB_C++;
				}
				if(chB == 'B')
				{
					countB_B++;
				}
				if(chB == 'J')
				{
					countB_J++;
				}
			}
		}
	}
	
	fflush(stdin);
	chA = find(countA_B, countA_C, countA_J);
	chB = find(countB_B, countB_C, countB_J);
	printf("%d %d %d\n", countA, countAB, countB);
	printf("%d %d %d\n", countB, countAB, countA);
	//printf("%d %d %d\n%d %d %d\n", countA_B, countA_C, countA_J, countB_B, countB_C, countB_J);
	printf("%c %c", chA, chB);
	return 0;
 } 
 
int flag(char a, char b)
{
 	int symbol = -1;
 	if(a == 'C' && b == 'J')
 	{
 		symbol = 1;
	}
	if(a == 'J' && b == 'B')
	{
		symbol = 1;
	}
	if(a == 'B' && b == 'C')
	{
		symbol = 1;
	} 
	if(a == b)
	{
		symbol = 0;
	}
	return symbol;
}

char find(int a, int b, int c)
{
	char ch;
	int max = a;
	if(max < b)
	{
		max = b;
	}
	if(max < c)
	{
		max = c;
	}
	if(max == 0)
	{
		ch = 'B';
	}
	else
	{
		if(max == a)
		{
			ch = 'B';
		}
		else
		{
			if(max == b)
			{
				ch = 'C';
			}
			else
			{
				ch = 'J';
			}
		}
	}
	return ch;
}
