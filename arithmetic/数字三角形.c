#include<stdio.h>
#include<string.h>

int data[100][100], arr[100][100];//data�������Ѿ��������ֵ arr������������������� 
int n;//����

int max(int x, int y)
{
	if(x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

int sum(int i, int j)
{
	int x, y;
	if(data[i][j] != -1)//�Ѿ������ 
	{
		return data[i][j];
	}
	if(i == n - 1)
	{
		return arr[i][j];
	}
	
	x = sum(i + 1, j);
	y = sum(i + 1, j + 1);
	data[i][j] = max(x, y) + arr[i][j];
	
	return data[i][j];
}

int main()
{
	int i = 0, j = 0;
	
	printf("����������������");
	scanf("%d", &n); 
	memset(data, -1, sizeof(data));
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < i + 1; j++)//�����Σ���i������i + 1��Ԫ�� 
		{
			scanf("%d", &arr[i][j]);
		}
	}
	printf("���·����Ϊ��%d", sum(0, 0));
	return 0;
}
