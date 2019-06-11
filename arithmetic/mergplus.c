/************************** 
�ó�����ͨ����΢�Ľ��鲢�������÷���˼�����һ�����е����������� 
����ʱ�临�Ӷ�ΪO(nlogn) 

�������Ϊ���룬��������ǴӴ�С�ź�����������߸��Ե�������
�ټ����ж����������������ȡһ�������ұ�ȡһ�������ɣ����������Ϊ
������е������� 
*******************************/ 
#include<stdio.h>
#include<string.h>

int array[100];

int mergsortandCount(int *arr, int head, int mid, int last)
{
	int i = head, j = mid + 1, k = 0, count = 0;
	while(i <= mid && j <= last)
	{
		if(arr[i] > arr[j])
		{
			array[k++] = arr[i++];
			count += (last - j + 1);
		}
		else
		{
			array[k++] = arr[j++];
		}
	}
	while(i <= mid)
	{
		array[k++] = arr[i++];
	}
	while(j <= last)
	{
		array[k++] = arr[j++];
	}
	memmove(arr + head, array, k * sizeof(array[0]));//���Ƶ�ԭ����ʱע�ⲻ��ֱ�Ӹ��Ƶ�arr�У����Ƶ�arr+head 
	return count;
}

int count(int *arr, int head, int last)
{
	int mid, count1 = 0, count2 = 0, count3 = 0;
	
	while(head < last)
	{
		mid = head + (last - head) / 2;
		count1 = count(arr, head, mid);					//���ܰ�head��0���棬֮��ݹ�ͷ�±겻һ����0 
		count2 = count(arr, mid + 1, last);				//�ڶ��鿪ʼ�����±�Ϊmid + 1������дΪmid 
		count3 = mergsortandCount(arr, head, mid, last);//���ܰ�head��0���棬֮��ݹ�ͷ�±겻һ����0 
	/*	printf("head = %d, last = %d\n", head, last);
		for(i = 0; i < 5; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		printf("count3 = %d\n", count3);*/ 
		return count1 + count2 + count3;
	}
	return 0;
}

int main()
{
	int arr[100];
	int i, count1, len;
	
	printf("please input the length:");
	scanf("%d", &len);
	for(i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	count1 = count(arr, 0, len - 1);
	printf("��������%d��\n", count1);
	return 0;
}
