#include<stdio.h>

int main()
{
	char strnum[1001] = {'\0'};
	int B, i = 1;
	int num1, num2;//num1��������num2�潫�ַ�ת�������� 
	
	scanf("%s",strnum);
	scanf("%d",&B);
	num2 = (int)(strnum[0] - '0');
	num1 = num2 % B;
	if(num2 >= B)
	{
		printf("%d", num2/B);
	 } 
	 while(strnum[i] != 0)
	 {
	 	num2 = (int)(strnum[i++] - '0');
	 	printf("%d", (num1 * 10 + num2) / B);
	 	num1 = (num1 * 10 + num2) % B;
	 }
	 if(strnum[1])
	 {
	 	 printf(" %d\n", num1);
	 }
	 else
	 {
	 	printf("0 %d\n", num1);
	 }
	return 0;
}
