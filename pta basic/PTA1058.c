/**********************
my faults:�޷��������� 
**********************/
#include<stdio.h>

#define Clear {\
					int ch;\
					while((ch = getchar()) != EOF && ch != '\n')\
					{\
					;\
					}\
			   }

struct {
	int score;//������� 
	int sumnum;//��ѡ����� 
	int truenum;//��ȷѡ����� 
	int falsenum;//��¼��Ĵ��� 
	char option[5];//��ȷѡ�� 
} issue[101];
struct{
	int selectnum;//ѡ�����
	char select[5];//ѡ���ѡ�� 
} student[1001][101];

int main()
{
	int stunum, issuenum, i, j, k, n, flag = 0, symbol = 1;//�Ƿ�ѡ�Եı�־ 
	int  maxfalsecount = 0, maxfalsenumber;
	int getscore[1001] = {0};//�����÷� 
	
	scanf("%d %d", &stunum, &issuenum);
	for(i = 0; i < issuenum; i++)
	{
		Clear
		issue[i].falsenum = 0;
		scanf("%d %d %d", &issue[i].score, &issue[i].sumnum, &issue[i].truenum);
		for(j = 0; j < issue[i].truenum; j++)
		{
			scanf("%c", &issue[i].option[j]);
		}
	}
//	system("pause");
	for(i = 0; i < stunum; i++)//��i��ѧ�� 
	{
		for(k = 0; k < issuenum; k++)//��k���� 
		{
			Clear
			scanf("(");
			scanf("%d", &student[i][k].selectnum);
		//	printf("student[%d][%d].selectnum = %d	",i, k, student[i][k].selectnum);
			for(j = 0; j < student[i][k].selectnum; j++)
			{
				scanf("%c", &student[i][k].select[j]);
			}
			scanf(")");
		//	printf("student[%d][%d].selectnum input OK\n", i, k, student[i][k].selectnum);
			if(student[i][k].selectnum != issue[k].truenum)
			{
				issue[k].falsenum++;
				symbol = 0;
			}
			else
			{
				//ͨ��������ÿ��ѡ������ȷѡ��Ա��жϵ�i��������k�����Ƿ���ȷ 
				flag = 0;
				n = 0;
				while(n < student[i][k].selectnum)//������i��ѧ���ĵ�k����Ŀ��ѡ�� 
				{
					for(j = 0; j < issue[k].truenum; j++)//������k����Ŀ����ȷѡ�� 
					{
						if(student[i][k].select[n] == issue[k].option[j])//�жϵ�i��ѧ����k����ĵ�n��ѡ���Ƿ���ȷ 
						flag++;
					}
					n++;
				}
				if(flag != student[i][k].selectnum)//��ȷ�����Ƿ����ѡ����� 
				{
					issue[k].falsenum++;
					symbol = 0;
				}
				else
				getscore[i] += issue[k].score; 
			}
		}
	}
	
	for(i = 0; i < stunum; i++)
	{
		printf("%d\n", getscore[i]);
	}
	if(symbol == 1)
	{
		printf("Too simple");
	}
	else
	{
		maxfalsecount = issue[0].falsenum;
		for(i = 0; i < issuenum; i++)
		{
			if(maxfalsecount < issue[i].falsenum)
			maxfalsecount = issue[i].falsenum;
		}
		printf("%d", maxfalsecount);
		for(i = 0; i < issuenum; i++)
		{
			if(issue[i].falsenum == maxfalsecount)
			{
				printf(" %d", i + 1);
			}
		}
	}
	printf("\n");
	return 0;
 } 
