#include<stdio.h>
void myself()
{
	printf("������ѧ�ţ���С����2018081104\n");
	printf("רҵ���༶���������183��\n");
	printf("���ü�����������Ӿ��û�з���Ĵ���������Զ������˳��\n");
	
}
void DisplayDigit()
{
	int x;
	printf("please input a number:\n");
	scanf("%d",&x);
	printf("%d\n",x);
}

void AddTwo()
{
	int a,b;
	printf("please input two number:\n");
	scanf("%d %d",&a,&b);
	printf("%d\n",a+b);
}
int main()
{
	myself();
	DisplayDigit();
	AddTwo();
	return 0;
}
