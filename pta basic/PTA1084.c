#include<stdio.h>
#include<string.h>

int main()
{
	int i, j, k, x;//���Ƶ���������ѭ���ı��� 
	int n, len, count; 
	char str[100000], temp[100000];
	
	scanf("%s %d", str, &n);
	for(i = 1; i < n; i++)
	{
		x = 0;
		len = strlen(str);
		for(j = 0; j < len; j++)
		{
			//����ÿ�����Ĵ��� 
			for(k = j, count = 0; k < len && str[k] == str[j]; k++)
			{
				count++;
			}
			j = k - 1;
			//������������Ĵ������䱾��ŵ�temp������ 
			temp[x] = str[j];
			temp[x + 1] = (char)(count + '0');
			x += 2;
		}
		temp[x] = '\0';
		strcpy(str, temp);
	}
	printf("%s\n", str);
	return 0;
}
