#include<stdio.h>
#include<string.h> 

struct _people{
	char name[9];
	int high;
} people[10005];
struct {
	char na[10];
} namestr[10005];

int cmp(const void *a, const void *b)
{
	struct _people *aa = (struct _people*)a;
	struct _people *bb = (struct _people*)b;
	if(aa->high > bb->high) return -1;
	if(aa->high < bb->high) return 1;
	else
	return strcmp(aa->name, bb->name);
}

int main()
{
	int N, K, a, n;//������������  a: ÿ�������� n����  
	int i = 0, j = 0, k = 0;
	
	scanf("%d %d", &N, &K); 
	n = K; 
	for(i = 0; i < N; i++)
	{
		scanf("%s %d", people[i].name, &people[i].high);
	}
	qsort(people, N, sizeof(people[0]), cmp);
	i = 0;
	while(n)
	{
		if(n == K)
		{
			a = N - N / K * (K - 1);
		}
		else
		{
			a = N / K;
		}
		//�Ƚ��м���˴������ 
		strcpy(namestr[a / 2].na, people[i].name);
		//�ٽ�����ߵ��˴�������м����� 
		for(j = i + 1, k = 1; j < i + a; j += 2, k++)
		{
			strcpy(namestr[a / 2 - k].na, people[j].name);
		}
		//���ұߵ���ͬ�� 
		for(j = i + 2, k = 1; j < i + a; j += 2, k++)
		{
			strcpy(namestr[a / 2 + k].na, people[j].name);
		}
		//������������źõ����� 
		printf("%s", namestr[0].na);
		for(j = 1; j < a; j++)
		{
			printf(" %s", namestr[j].na);
		}
		printf("\n");
		
		n--;
		i += a;
	}
	return 0;
}
