#include<stdio.h>
/*************************** 
���ܣ�����һ�����е�����������г��� 
***************************/
#include<string.h>

int data[100];   //���ڶ�̬�滮�����Ѽ���������� 
int arr[100];    //������������ 

int maxlen(int index) //����һ�������Ե�index����Ϊ�յ�ʱ����������г��� 
{
	int i = 1, max = 0, temp = 0;
	
	if(data[index] != -1)
	{
		return data[index];
	}
	if(index == 1)
	{
		data[index] = 1;
		return 1;
	}

	for(i; i < index; i++)     //�������е�index��ǰ���������յ����ȵ�index��С�������ҳ��յ�����������г��� 
	{
		if(arr[i - 1] <= arr[index - 1])
		{
			data[i] = maxlen(i);
			if(max < data[i])
			{
				max = data[i];
			}
		}
	}
	return max + 1;      //��index��������г�����Ϊǰ������max�����Լ�������max+1 
}

int main()
{
	int i, len, max = 1;
	 
	memset(data, -1, sizeof(data));
	scanf("%d", &len);
	for(i = 0; i < len; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(i = 1; i <= len; i++) //�ֱ���������и�����Ϊ�յ����������г��ȣ��������Ǹ���������������г��� 
	{
		if(maxlen(i) > max)
		{
			max = maxlen(i);
		}
	}
	printf("������������������г���Ϊ��%d\n",max);
	return 0;
}
