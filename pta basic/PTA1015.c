/*************************************
my faults:���ر����ռ䲻�������Զ���ȫ�֣��ֵ�����ѧ��ʱ���˵Ⱥ� 

**************************************/
/************************ 
��һ�ࣺ�·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ����
�ڶ��ࣺ�ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�� 
�����ࣺ�²ŷ־����� H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼���
�����ࣺ�����ﵽ����� L �Ŀ���Ҳ���ܷ�����
*************************/ 

#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b);

typedef struct {
	int stunum;
	char Dscore;//�洢�������������������ã���ʡ�ռ� 
	char Cscore;
	char sumscore;
} Student;

Student kind1[100005], kind2[100005], kind3[100005], kind4[100005];//����ѧ�� 

int main()
{
	int N, L, H;//ѧ������������֣������ 
	int i = 0, j = 0, len1, len2, len3, len4; //����ѧ������ 
	Student student[100005];
	
	scanf("%d %d %d", &N, &L, &H);
	for(i = 0; i < N; i++)
	{
		scanf("%d %d %d", &student[i].stunum, &student[i].Dscore, &student[i].Cscore);
	}
	for(i = 0; i < N; i++)
	{
		student[i].sumscore = student[i].Cscore + student[i].Dscore;
	} 
	for(i = 0, j = 0; i < N; i++)
	{
		if(student[i].Dscore >= H && student[i].Cscore >= H)//��һ�� 
		{
			kind1[j] = student[i];
			j++;
		}
	}
	len1 = j;
	for(i = 0, j = 0; i < N; i++)
	{
		if(student[i].Dscore >= H && student[i].Cscore < H && 
		student[i].Cscore >= L && student[i].Dscore >= L)//�ڶ��� 
		{
			kind2[j] = student[i];
			j++;
		}
	}
	len2 = j;
	for(i = 0, j = 0; i < N; i++)
	{
		if(student[i].Dscore < H && student[i].Cscore < H && 
		student[i].Dscore >= student[i].Cscore && student[i].Cscore >= L && student[i].Dscore >= L)//������ 
		{
			kind3[j] = student[i];
			j++;
		}
	}
	len3 = j;
	for(i = 0, j = 0; i < N; i++)
	{
		if(student[i].Dscore < H &&
		student[i].Dscore < student[i].Cscore && student[i].Cscore >= L && student[i].Dscore >= L)
		{
			kind4[j] = student[i];
			j++;
		}
	}
	len4 = j;
	//�����ֿ����ֱ�������� 
	qsort(kind1, len1, sizeof(kind1[0]), cmp);
	qsort(kind2, len2, sizeof(kind2[0]), cmp);
	qsort(kind3, len3, sizeof(kind3[0]), cmp);
	qsort(kind4, len4, sizeof(kind4[0]), cmp);
	
	printf("%d\n", len1 + len2 + len3 + len4);
	for(i = 0; i < len1; i++)
	{
		printf("%08d %d %d\n", kind1[i].stunum, kind1[i].Dscore, kind1[i].Cscore);
	}
	for(i = 0; i < len2; i++)
	{
		printf("%08d %d %d\n", kind2[i].stunum, kind2[i].Dscore, kind2[i].Cscore);
	}
	for(i = 0; i < len3; i++)
	{
		printf("%08d %d %d\n", kind3[i].stunum, kind3[i].Dscore, kind3[i].Cscore);
	}
	for(i = 0; i < len4; i++)
	{
		printf("%08d %d %d\n", kind4[i].stunum, kind4[i].Dscore, kind4[i].Cscore);
	}
	return 0;
}

int cmp(const void *a, const void *b)
{
	Student *aa = (Student*)a;
	Student *bb = (Student*)b;
	if (aa->sumscore < bb->sumscore) return 1;   
	if (aa->sumscore > bb->sumscore) return -1;  
	if (aa->Dscore > bb->Dscore) return -1;    
	if (aa->Dscore < bb->Dscore) return 1;    
	if (aa->stunum > bb->stunum) return 1;
	else return -1;
}
