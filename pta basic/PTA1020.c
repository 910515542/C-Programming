/********************************
my faults:���ⲻ��ϸ����Ϊ�������ۼۣ�ƽ���۸��������������¶���������� 
************************************/
#include<stdio.h>
#include<stdlib.h>

struct _kind {
	double sum;//��� 
	double sumprice;//���ۼ�
	double oneprice; //ƽ���۸� 
} kind[1005];//����±����࣬

int cmp(const void *a, const void *b)
{
	struct _kind *aa = (struct _kind *)a;
	struct _kind *bb = (struct _kind *)b;
	return ((aa->oneprice) < (bb->oneprice)?1:-1);
}

int main()
{
	int i, j, N, need;//N.need�������г�������
	double totalprice = 0;//�������  
//	double oneprice[1000] = {0};//����±����� 
//	struct _kind temp;
	
	scanf("%d %d", &N, &need);
	//��������N���±���� 
	for(i = 0; i < N; i++)
	{
		scanf("%lf", &(kind[i].sum));
	}
	//��������N���±������۶� 
	for(i = 0; i < N; i++)
	{
		scanf("%lf", &(kind[i].sumprice));
	}
	//��ÿ���±���ƽ��ֵ������˳����oneprice������ 
	for(i = 0; i < N; i++)
	{
		kind[i].oneprice = (kind[i].sumprice) * 1.0 / (kind[i].sum);
	}
 	//����ǰ�ṹ����������� 
/*	for(i = 0; i < N; i++)
	{
		printf("%d %d\n", kind[i].sumprice, kind[i].sum);
	}
	printf("\n\n");
	//�����±�ƽ��ֵ�Խṹ������
	for(i = 1; i < N; i++)
	{
		for(j = 0; j < N - i; j++)
		{
			if( oneprice[j] < oneprice[j + 1] );
			{
				temp = kind[j];
				kind[j] = kind[j + 1];
				kind[j + 1] = temp;
			}
		}
	}
	qsort(kind, N, sizeof(kind[0]), cmp);
	//�����ṹ������� 
	for(i = 0; i < N; i++)
	{
		printf("%d %d\n", kind[i].sumprice, kind[i].sum);
	}
	printf("\n\n");*/
	qsort(kind, N, sizeof(kind[0]), cmp);
	//�����г�����need����������� 
	i = 0;
	while( i < N )
	{
		if( need >= (kind[i].sum) )
		{
			totalprice += (kind[i].sumprice);
		}
		else
		{
			totalprice = totalprice + need * kind[i].oneprice;
			break;
		}
		need -= (kind[i].sum);
		i++;
	}
	printf("%.2f\n", totalprice);
	return 0;
}
