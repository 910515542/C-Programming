#include<stdio.h>
#include<string.h>

int main()
{
	int i, count, j, len;
	char ch, str[1005];
	
	scanf("%c", &ch);
	getchar();
	gets(str);
	len = strlen(str);
	if(ch == 'C')
	{
		for(i = 0; i < len; i++)
		{
			//��Ϊ���һ���ַ�ʱ������str[i + 1]�ж� 
			if(i == len - 1)
			{
				printf("%c", str[i]);
				break;
			}
			if(str[i] != str[i + 1])
			{
				printf("%c", str[i]);
			}
			else
			{
				//�����ж��ٸ��ظ��ַ� 
				for(j = i, count = 0; j < len; j++)
				{
					if(str[j] == str[i])
					{
						count++;
					}
					else
					{
						break;
					}
				}
				printf("%d%c", count, str[i]);
				//���һֱ�ظ������ֱ�ӽ���ѭ�� 
				if(j == len)
				break;
				i = j - 1;
			}
		}
	}
	else
	{
		for(i = 0; i < len; i++)
		{
			if(str[i] == '1' && str[i + 1] == '0')
			{
				for(j = 1; j < 10; j++)
				{
					printf("%c", str[i + 2]);
				}
				i++;
			}
			else
			{
				if(str[i] >= '0' && str[i] <= '9')
				{
					for(j = 1; j < str[i] - '0'; j++)
					{
						printf("%c", str[i + 1]);
					}
				}
				else
				{
					printf("%c", str[i]);
				}
			}
		}
	}
	return 0;
}
