/******************88
my faults:�𰸴��� 
******************/
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int main()
{
	int n, sumscore, i, j, k = 0, temp;
	int tescore[105] = {0}, stuscore[105][105] = {0}, len[105] = {0};
	//ÿ����ʦ���֣�ѧ������, ÿ����Чѧ���������� 
	double score;
	
	scanf("%d %d", &n, &sumscore);
	//����ÿ��ķ��� 
	for(i = 0; i < n; i++)
	{
		flag = 1;
		for(j = 0, k = 0; j < n; j++)
		{
			if(j == 0)
			{
				scanf("%d", &tescore[i]);//��ʦ���� 
			}
			else
			{
				scanf("%d", &temp);
				if(temp >= 0 && temp <= sumscore)
				{
					stuscore[i][k++] = temp;//ѧ������ 
				}
			}
		}
		len[i] = k; //�������ѧ����Ч�������� 
	}
	//��ÿ��ѧ������Ч�������� ���Ӷ�ȥ��-�����ֵ����Сֵ 
	for(i = 0; i < n; i++)
	{
		qsort(&stuscore[i][0], len[i], sizeof(stuscore[0][0]), cmp);
	}
/*	for(i = 0; i < n; i++)
	{
		for(j = 0; j < len[i]; j++)
		{
			printf("%d ", stuscore[i][j]);
		}
		printf("\n");
	}
	system("pause");*/
	for(i = 0; i < n; i++)
	{
		//ȥ����һ����ͷ������һ����߷� 
		for(j = 1, score = 0; j < len[i] - 1; j++)
		{
			score += stuscore[i][j];
		}
		score = score / (len[i] - 2);
		score = (score + tescore[i]) * 1.0 / 2;
		printf("%.0f\n", score);//���������������÷� 
	}
	return 0;
}
