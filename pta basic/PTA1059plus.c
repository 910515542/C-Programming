#include<stdio.h>
#include<math.h>

int judge(int num);//�ж�num�Ƿ�Ϊ���� 

int main()
{
	int student[10005] = {0}, i, j, N, K, temp;//�������±�Ϊid���������� 
	int count[10005] = {0}, id[10005];//checkidarr����id��checkid��idΪ�±괢��id��Ϣ �����ֵĴ����� 
	scanf("%d", &N);
	for(i = 1; i <= N; i++)//�������±�Ϊid���������� 
	{
		scanf("%d", &temp);
		student[temp] = i;
	}
	scanf("%d", &K);
	for(i = 0; i < K; i++)
	{
		scanf("%d", &id[i]);
	}
	for(i = 0; i < K; i++)
	{
		if(student[id[i]] == 0)//�����ڵ�id����Ϊ��ʼ��ʱֵ0 
		{
			printf("%04d: Are you kidding?\n", id[i]);
		}
		else
		{
			count[id[i]]++;//����һ�Σ��Ը�id�Ĳ��Ҵ���+1. 
			if(count[id[i]] > 1)//�ظ������id 
			{
				printf("%04d: Checked\n", id[i]);
			}
			else
			{
				if(student[id[i]] == 1)//����Ϊ��һ��id 
				{
					printf("%04d: Mystery Award\n", id[i]);
				}
				else
				{
				//	printf("%d %d\n", student[id[i]], judge(student[id[i]]));
					if(judge(student[id[i]]))//����Ϊ������id 
					{
						printf("%04d: Minion\n", id[i]);
					}
					else//��������������id 
					{
						printf("%04d: Chocolate\n", id[i]);
					}
				}
			}
		}
	}
	return 0;
}

int judge(int num)
{
	int i, symbol, flag;
	
	symbol = (int)pow(num, 0.5);
	for(i = 2, flag = 1; i <= symbo; i++)
	{
		if(num % i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
