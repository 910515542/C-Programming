#include<stdio.h>

void q_sort(int *arr, int len)
{
	int i = 0, j = len - 1, key;
	//��һ�η���ȡ��һ��ֵΪ�ؼ�ֵ��������ȹؼ�ֵС�Ķ������������ߣ���Ķ����������ұ� 
	key = arr[0];
	if(len > 1)//�����ݹ������ 
	{
		while(i != j)//i = j��������� 
		{
			for(; j > i; j--)
			{
				if(arr[j] < key)
				{
					arr[i] = arr[j];
					break;
				}
			}
			for(; i < j; i++)
			{
				if(arr[i] > key)
				{
					arr[j] = arr[i];
					break;
				}
			}
			arr[i] = key;
		}
		q_sort(arr, i);//��key�����߽��з��� �����ٽ�keyֵ�������ڣ��������߳���i + ��len - i - 1�� ��= len�� 
		q_sort(arr + i + 1, len - i - 1);
	}
}

int main()
{
	int arr[10] = {2, 4, 1, 8, 5, 0, 9, 8, 6, 3};
	int i;
	
	q_sort(arr, 10);
	for(i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
