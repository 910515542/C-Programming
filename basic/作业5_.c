#include<stdio.h>
#include<math.h>
//�ж����꺯�� 
void Feb_days()
 {
 	int year,days;
 	printf("��������ݣ�"); 
 	scanf("%d",&year);
 	if((year%4==0&&year%100!=0)||year%400==0)
 	{
 		days=29;
	 }
	 else
	 {
	 	days=28;
	 }
	printf("����2�·�����Ϊ��%d\n",days);
  } 
//����ֶκ��� 
int func()
{
	double x=0;
	printf("�������Ա���ֵx=");
	scanf("%lf",&x);
	if(x>0)
	{
		printf("����ֵy=%f\n",exp(-x));
	 } else
	 {
	 	if(x==0)
	 	{
	 		int y=1;
	 		printf("����ֵy=%d\n",y);
		 }else
		 {
		 	printf("����ֵy=%f\n",-exp(-x));
		 }
		}
		return 0;
}
// �򵥼��������� 
void caculator()
{
	double x=0;
	double y=0;
	char a;
	printf("��������������");
	scanf("%lf",&x);	
	fflush(stdin); 
	printf("������������ţ�\n"); 
	a=getchar();
	printf("��������������\n");
	scanf("%lf",&y);
	if(a=='/'&&y==0)
	{
		printf("�������!0������������");
	}else
	{
	 switch(a)
	{
		case '+': printf("%f+%f=%f\n",x,y,x+y);break;
		case '-': printf("%f-%f=%f\n",x,y,x-y);break;
		case '*': printf("%f*%f=%f\n",x,y,x*y);break;
		case '/': printf("%f/%f=%f\n",x,y,x/y);break;
		default:printf("�����������������룡"); 
	}
	 }
      }
//˰����㺯�� 
void Tax()
{
	double bonus,rate;
  	printf("�����뽱��"); 
  	scanf("%lf",&bonus);
  	if(bonus<5000)
  	{
		switch((int)(bonus/500))
	{
		case 0:rate=0;break;
		case 1:rate=0.05;break;
		case 2:case 3:rate=0.08;break;
		case 4:case 5:case 6:case 7:case 8:case 9:rate=0.10;break;
	}
	}else
	{
		rate=0.15;
	}
	printf("bonus=%f	rate=%f	tax=%f	profit=%f\n",bonus,rate,bonus*rate,bonus-bonus*rate); 
}
//������ϰ���� 
int MathLearn()
{
	int a,b,i,c;
	int d=0;
	int answer=0;
	do 
	{
		srand(time(0));
		a=rand()%11;
		b=rand()%11;
		c=rand()%4;
		if(c==1&&a-b<0)
		{
			printf("\n������������Ϊ���������������г���������Ŀ��\n");	
		}else
		{if(c==3&&a%b!=0)
		{
			printf("\n���������������Ϊ�������������г���������Ŀ��\n");
		}else
		{
			switch(c)
		{
			case 0:d=a+b;printf("\n̫��������!��ֻ��һ���򵥵ļӷ���:%d+%d=",a,b);break;
			case 1:d=a-b;printf("\n̫��������!��ֻ��һ���򵥵ļ�����%d-%d=",a,b);break;
			case 2:d=a*b;printf("\n���ͣ�����˷���Ҳ���Ǻ���Ŷ:%d*%d=",a,b);break;
			case 3:d=a/b;printf("\n�Ҳ����������Ҳ�Ѳ�����Ŷ:%d/%d=",a,b);break; 
			}
			scanf("%d",&answer);
			if(answer==d)
			{
				printf("\nRight!(���Ȼ������ģ�)\n");
			}else
			{
				printf("\nNot Correct!Try again!(���Ҳ��Ҫ����Ŷ��)\n");
			}
				}
					}
					printf("����1��������,����0��������:");
					scanf("%d",&i); 
						}
	while(i);
	
	return 0;
}
int menu()
{
	int iselect;
	printf("\n************************\n");
	printf("\n�����������躯��ָ����ţ�");
	printf("\n 1:���к������ж����꺯��"); 
	printf("\n 2:���к���������ֶκ���"); 
	printf("\n 3:���к������򵥼���������"); 
	printf("\n 4:���к�����˰����㺯��"); 
	printf("\n 5:���к�����������ϰ���� "); 
	printf("\n 0:�˳���"); 
	printf("\n************************\n");
	printf("����������ѡ�");
	scanf("%d",&iselect);
	return iselect; 
}
