#include<stdio.h>
#include<math.h>//pow����ͷ�ļ� 
#include<stdlib.h>//rand����ͷ�ļ� 
int Area(int a,int b, int c);
int rand();
int main()
{	int a,b,c;
	printf("��ֱ��������������߱߳���\n");
	scanf("%d %d %d",&a,&b,&c);
	printf("���������Ϊ��%d\n",Area(a,b,c)); 
	mathlearn();//���ú��� 
	return 0;
}
int Area(int a,int b, int c)
{
	int s,p;
	p=(a+b+c)/2;
	s=pow(p*(p-a)*(p-b)*(p-c),0.5);
	return s;
}

int mathlearn()
{
	//srand(time(0));
	int a;	 
	//int number1 = rand()%101;
	//int number2 = rand()%101;
	int number3 = rand()%101;
	int number4 = rand()%101;
	printf("\n%d+%d= \n",number3,number4);
	scanf("%d",&a);
	return 0;
}


 
	
