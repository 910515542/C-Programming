#include<stdio.h>

int main()
{
	int t1, n, i, num1[101], num2[101], b[101], t2[101];
	/*t1:���ͳ����� n����Ϸ���� num1��ϵͳ�����ĵ�һ������
	num2���ڶ������� b����ҲµĴ��С t2�������ע��*/
	int total;
	
	scanf("%d %d", &t1, &n);
	total = t1;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &num1[i], &b[i], &t2[i], &num2[i]);
	}
	for(i = 0; i < n; i++)
	{
		if(total > 0)
		{ 
			if(t2[i] > total)
			{
				printf("Not enough tokens.  Total = %d.\n", total);
			}
			else
			{
				if( (num1[i] < num2[i] && b[i] == 1) || (num1[i] > num2[i] && b[i] == 0))
				{
					total += t2[i];
					printf("Win %d!  Total = %d.\n", t2[i], total);
				}
				else
				{
					total -= t2[i];
					if(total < 0)
					total = 0;
					printf("Lose %d.  Total = %d.\n", t2[i], total);
				}
				
			}
		}
		if(total <= 0)
		{
			printf("Game Over.\n");
			break;
		}
	} 
	return 0;
} 
