#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int num1,num2,num3,num4=0;
	for(num1=0;num1<=3;num1++)
	{
		for(num2=0;num2<=3;num2++)
		{
			num3=8-(num1+num2);
			if((8-(num1+num2))>1&&(8-(num1+num2))<7)
			{
				printf("%d����ɫ��%d��ɫ��%d��ɫ��\n",num1,num2,num3);
				num4++; 
			}
		}
	}
	printf("\n����%d��\n",num4);
	return 0;
}
