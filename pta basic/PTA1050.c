/*******************************
my faults:1�����һȦֻ��һ����ʱ�޷���ֵ 
		  2�����г�ʱ�� 

************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a, const void *b)
{
	return *((int*)b) - *((int*)a);
}

struct _arr {
	int lie[10000];
} *hang;

int main()
{
	int a, b, i, j, k, n, N, *arr;//���������� 
	int temp; 

	scanf("%d", &N);
	arr = (int*)malloc(N * sizeof(int));
	for(i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	//�ҳ����������� 
	a = 1;
	b = N;
	for(i = (int)sqrt(N); i <= N && a - b < 0; i++)
	{
		if(N % i == 0)
		{
			a = i;
			b = N / i;
		}
	}
//	printf("a = %d, b = %d\n", a, b); 
	hang = (struct _arr*)malloc(sizeof(struct _arr) * a);
	qsort(arr, N, sizeof(arr[0]), cmp);
	//������˳ʱ�뷽���ź����arr�����ά����hang�� 
	n = 0;
	k = 1;
	while(n < N)
	{
	//һȦΪһ��ѭ����һȦ�����ĸ�ѭ�� 
		i = k - 1;
		j = k - 1;
	//���һȦΪһ����ʱ��ֵ 
		if( n == N - 1)
		{
			hang[i].lie[j] = arr[n++];
			break; 
		}
		//����������һ�� 
		/****************
		���ĸ�whileѭ�����n < NΪ�˷�ֹ���ĸ�ѭ��������n > N 
		*****************/
		while(j < b - k && n < N)
		{
			hang[i].lie[j++] = arr[n++];
		}
		//�������ұ�һ�� 
		while(i < a - k && n < N)
		{
			hang[i++].lie[j] = arr[n++];
		}
		//��������һ����
		while(j > k - 1 && n < N)
		{
			hang[i].lie[j--] = arr[n++];
		}
		//���������һ��	
		while(i > k - 1 && n < N)
		{
			hang[i--].lie[j] = arr[n++];
		}
		k++;
	}
	
	for( i = 0; i < a; i++)
	{
		for(j = 0; j < b; j++)
		{
			if(j == b - 1)
			{
				printf("%d\n", hang[i].lie[j]);
			}
			else
			printf("%d ", hang[i].lie[j]);
		} 
	}
	free(hang);
	free(arr); 
	return 0;
}
