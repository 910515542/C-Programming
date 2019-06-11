#include<stdio.h>
#include<string.h>

//�ж��Ƿ�Ϊ������ 
int check(char *str)
{
	int i, j, len;
	
	len = strlen(str);
	for(i = 0, j = len - 1; i <= j; i++, j--)
	{
		if(str[i] != str[j])
		return 0;
	}
	return 1;
}
void add(char str1[], char str2[])
{
	int i, len, sum, num1 = 0;
	//num1:���λ���Ƶ��� 
	len = strlen(str1);
	for(i = len - 1; i >= 0; i--)
	{
		sum = str1[i] - '0' + str2[i] - '0' + num1;
		str1[i] = sum % 10 + '0';
		num1 = sum / 10;
	}
	if(num1)//���ǵ��������λ����������ڵ���10�����ֳ���Ҫ��ԭ����1����λ 
	{
		memmove(str1 + 1, str1, len + 1);//�����ַ�������\0��������len + 1 
		str1[0] = num1 + '0';
	}
	
}
int main()
{
	int i, j, len;
	char num1[1005], num2[1005];
	gets(num1);
	
	for(i = 0; i < 10; i++)
	{
		if(check(num1))
		{
			printf("%s is a palindromic number.",num1);
			break;
		}
		len = strlen(num1);
		//���ַ���num1���� 
		for(j = 0; j < len; j++)
		{
			num2[len - j - 1] = num1[j];
		}
		num2[len] = 0; 
		printf("%s + %s = ", num1, num2);
		add(num1, num2);
		printf("%s\n", num1);
		if(check(num1))
		{
			printf("%s is a palindromic number.",num1);
			break;
		}
	}
	if(i==10)
   	{
 		printf("Not found in 10 iterations.");
	}
	return 0;
}
