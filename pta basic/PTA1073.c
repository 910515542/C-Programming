#include<stdio.h>

//ÿ����ĵ���Ϣ 
struct {
	int number;//���� 
	int score;
	int truenum;//��ȷѡ����� 
	char answer[6];//��ȷѡ��
	//����ѡ���Ĵ��� 
	int issuenum[5];
} question[101];

int main()
{
	int stunum, quenum, num1, num2;
	//num1:��Ŀѡ�������num2��ѧ����ѡ���� 
	int i, j, flag, count1 = 0;
	//count1:
	char ch;
	double stuscore[1001] = {0};
	
	scanf("%d %d", &stunum, &quenum);
	//���벢��ʼ����Ŀ��Ϣ 
	for(i = 0; i < quenum; i++)
	{
		question[i].number = i + 1;//������ 
		//������Ŀ������ѡ���������ȷѡ����� 
		scanf("%d %d %d", &question[i].score, &num1, &question[i].truenum);
		//��ʼ����Ŀ��ѡ�������� 
		for(j = 0; j < num1; j++)
		{
			question[i].issuenum[j] = 0;
		}
		//������Ŀ��ȷѡ�� 
		for(j = 0; j < question[i].truenum; j++)
		{
			scanf("%c", question[i].answer[j]);
		}
	}
	for(i = 0; i < stunum; i++)
	{
		for(j = 0; j < quenum; j++)
		{
			flag = 1;//�ж�ѧ���Ƿ��д���ѡ�� 
			scanf("(");
			scanf("%d", &num2); 
			for(k = 0; k < num2; k++)
			{
				scanf("%c", &ch);
				for(m = 0; m < question[j].truenum; m++)
				{
					if(ch != question[j].answer[m])
					{
						//��Ŀ��Ӧѡ����������һ 
						question[j].issuenum[question[j].answer[m]-'a']++;
					}
					else
					{
						flag = 1;
					}
				}
				if(num2 < question[j].truenum && flag)
				{
					stuscore[i] += (question[j].score * 1.0 / 2);
				}
				if(num2 == question[j].truenum && flag)
				{
					stuscore[i] += question[j].score;
				}
			}
			scanf(")"); 
		}
	} 
	return 0;
}
