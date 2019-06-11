#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*���Ѿ�������������������У�left - mid��mid+1 - right��
�鲢�����һ���µ����������� */
void mergadd(int *arr, int left, int mid, int right, int *p)
{
	int i = left, j = mid + 1, k = 0;
	if(arr[mid] > arr[mid + 1])//�Ż������ǰһ�������������һ��Ԫ��С�ڵ��ں�һ���������е�һ��Ԫ�����ù鲢 
	{
		while(i <= mid && j <= right)
		{
			if(arr[i] < arr[j])
			{
				p[k++] = arr[i++];
			}
			else
			{
				p[k++] = arr[j++];
			}
		}
		while(i <= mid)
		{
			p[k++] = arr[i++];
		}
		while(j <= right)
		{
			p[k++] = arr[j++];
		}
		memcpy(arr+left, p, sizeof(int) * k);
	}
}

void mergsort1(int *arr, int left, int right, int *p, int len)
{
	int i, j, k = 1;
	/*�ʼ�� ����ÿ��Ԫ�ؿ���һ���������ԣ����������鲢��
	�γ�һ���µ���������;
	������һ��ѭ�������γɵ��������������鲢��ֱ�����ֻʣ��һ����������*/ 
	while(1)
	{
		for(j = 0, i = 0; j < len; j += (2 * k), i++)
		{
			if(j + 2 * k - 1 >= len)
			{
				mergadd(arr, j, (j + len - 1) / 2, len - 1, p);
				break;
			}
			else
			{
				mergadd(arr, j, j + k - 1, j + 2 * k - 1, p);
			}
		}
		/*����鲢����ֻ���������Σ���i = 1����˵��ֻʣ�����������������
		��������һ�ι鲢�����γ�һ���������У����ɽ���ѭ����*/ 
		if(i == 1)
		{
			mergadd(arr, 0, j - 1, len - 1, p);
			break;
		}
		k *= 2;
	}
}
/*���õݹ齫����ֳ�n������Ԫ�ص��������ԣ�
Ȼ��ӵ���Ԫ���������Կ�ʼ�鲢����ֱ���鲢��һ����������*/ 
void mergsort2(int *arr, int left, int right, int *p)
{
	int mid;
	//�Ż�������������鳤�Ȳ������ò��������������Ч�ʸ��� 
	if(left < right)
	{
		mid = (left + right) / 2;
		mergsort2(arr, left, mid, p);
		mergsort2(arr, mid + 1, right, p);
		mergadd(arr, left, mid, right, p);
	}
}

int main()
{
	int arr[10], i, *p, len;
	
	p = (int*)malloc(sizeof(int) * 11);
	//�ǵݹ�ʵ�ֹ鲢���� 
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergsort1(arr, 0, 9, p, 10);
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//�������õݹ�ʵ�ֹ鲢���� 
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	mergsort2(arr, 0, 9, p);
	for(i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

