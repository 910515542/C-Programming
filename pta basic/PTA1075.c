#include<stdio.h>

struct {
	int data, next;
} node[100000];

int first[100000], second[100000], third[100000];

int main()
{
	int n, k, i, address1, temp;
	int j = 0, m = 0, x = 0;
	
	scanf("%d %d %d", &address1, &n, &k);
	//��һ������ַ�������������Χ���� 
	for(i = 0; i < n; i++)
	{
		scanf("%d", &temp);//�������±��ʾ�����ַ 
		scanf("%d %d", &node[temp].data, &node[temp].next);
	}
	for(i = address1; i != -1; i = node[i].next)
	{
		if(node[i].data < 0)
		{
			first[j++] = i;
		}
		else
		{
			if(node[i].data >= 0 && node[i].data <= k)
			{
				second[m++] = i;
			}
			else
			{
				third[x++] = i;
			}
		}
	}
	//������ֱ���� 
	for(i = 0; i < j; i++)
	{
		//ע��ı�ÿ������next 
		if(i == j - 1)
		printf("%05d %d %05d\n", first[i], node[first[i]].data, second[0]);
		else
		printf("%05d %d %05d\n", first[i], node[first[i]].data, first[i + 1]);
	}
	for(i = 0; i < m; i++)
	{
		if(i == m - 1)
		printf("%05d %d %05d\n", second[i], node[second[i]].data, third[0]);
		else
		printf("%05d %d %05d\n", second[i], node[second[i]].data, second[i + 1]);
	}
	for(i = 0; i < x; i++)
	{
		if(i != x - 1)
		printf("%05d %d %05d\n", third[i], node[third[i]].data, third[i + 1]);
		else
		printf("%05d %d -1\n", third[i], node[third[i]].data);
	}
	if(address1 == -1)
	printf("-1\n");
	return 0;
}
