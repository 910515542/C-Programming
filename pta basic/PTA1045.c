/***********************
my faults������ÿ���������ȣ�ȷ��λ�ú�ֻ�迴ǰ�沿�ָ����ǲ�������
			��β�����ж���ո�ʱӦ������һ�л��У�����%d\n; 
*************************/ 
#include<stdio.h>

int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}

int main()
{
	int N, i, j, flag, k, max;
	int arr1[100005], arr2[100005], arr3[100005];//�����룬�����������룬 ����Ԫ 
	
	scanf("%d", &N);
	if(N > 0)
	{
		for(i = 0; i < N; i++)
		{
			scanf("%d", &arr1[i]);
			arr2[i] = arr1[i];
		}
		max = arr1[0];
	/*	for(i = 0; i < N; i++)
		{
			printf("%d ", arr1[i]);
		}
		printf("\n");*/
		qsort(arr2, N, sizeof(arr2[0]), cmp);
	/*	for(i = 0; i < N; i++)
		{
			printf("%d ", arr2[i]);
		}
		printf("\n");*/
		for(i = 0, j = 0; i < N; i++)
		{
			if(max < arr1[i])
			{
				max = arr1[i];
			}
			if(arr1[i] == arr2[i] && max == arr1[i])//�ҳ�ԭ��������������������λ����ͬ��Ԫ�� ����Ԫ��ǰ��û�б�����ģ���û�������Ҳû�б���С�ģ����Ԫ������Ԫ�� 	
			{
				arr3[j++] = arr1[i];
			}
		}
	}
	else j = 0;

	printf("%d\n", j);
	for(i = 0; i < j; i++)
	{
		if(i == j - 1)
		{
			printf("%d", arr3[i]);
		}
		else
		{
			printf("%d ", arr3[i]);
		}
	}
	printf("\n");//\n���������󣬲��� printf("%d\n", arr3[i]);
	return 0;
 } 
