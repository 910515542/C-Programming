#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
	return *((int*)a) - *((int*)b);
}
//��װ�䵥�� 
struct {
	int goods[1005];
} arr1[105];
//�����ݵĻ��� 
struct {
	int a;
	int b;
} arr2[10005];

int search(int *arr, int len, int a)
{
	int head = 0, last = len - 1, mid, flag = 0;
	
	while(head <= last)
	{
		mid = (head + last) / 2;
		if(arr[mid] < a)
		{
			head = mid + 1;
		}
		else
		{
			if(arr[mid] > a)
			{
				last = mid - 1;
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
/*������Ʒ�嵥���鼰���ȣ���һ�Բ�����һ��Ļ�Ʒ���
 ����嵥�д�����Ի�Ʒ���򷵻�1�����򷵻�0*/ 
int check(int *arr, int len, int a, int b)
{
	int flag1 = 0, flag2 = 0, flag = 0;
	
	flag1 = search(arr, len, a);
	flag2 = search(arr, len, b);
	if(flag1 && flag2)
	{
		flag = 1;
	}
	return flag;
}

int main()
{
	int	n, m, k;
	int i, j;
	
	scanf("%d %d", &n, &m); 
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &arr2[i].a, &arr2[i].b);
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d", &k);
		for(j = 0; j < k; j++)
		{
			scanf("%d", &arr1[i].goods[j]);
		}
		qsort(arr1[i].goods, k, sizeof(arr1[i].goods[0]), cmp);
		for(j = 0; j < n; j++)
		{
			if(check(arr1[i].goods, k, arr2[j].a, arr2[j].b))
			{
				printf("No\n");
				break;
			}
		}
		if(j == n)
		{
			printf("Yes\n");
		}
	}
	return 0;
}
