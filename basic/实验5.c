#include<stdio.h>
int Greatest_Common_Divisor(int p,int q);
void StatisticsNum();
void Statisticschar();
int Statisticsmax();
void apple();
void Count();
int Pattern();
void perfectnum();
int perfectnum1(int x);
void perfectnum2();
int menu(); 
int DaffordiNum();
void GetBall(); 
int main()
{   
	int p,q,i=0;
	do 
	{
		switch(menu())
		{
			case 1:printf("����������������\n"); 
				   scanf("%d %d",&p,&q);
				   printf("���Լ��Ϊ��%d\n",Greatest_Common_Divisor(p,q));
				   break;
			case 2:StatisticsNum();break;
			case 3:Statisticschar();break;
			case 4:Statisticsmax();break;
			case 5:apple();break;
			case 6:Count();break;
			case 7:Pattern();break;
			case 8:perfectnum();break;
			case 9:perfectnum2();break;
			case 10:DaffordiNum();break;
			case 11:GetBall();break;
			case 12:MathLearn();break;
			case 0:break;
			default:printf("\n��ʽ����\n");break; 
		}
		printf("\n��Ҫ�������к���������1����������0��");
		scanf("%d",&i);
	}
	while(i);
	return 0;
}
int Greatest_Common_Divisor(int p,int q)
{
	int r,a,g;
	if(p<q)
	{
		a=q;
		q=p;
		p=a;
	}
		do
		{	
			r=p%q;
			if(r==0)
			{
				break;
			}else
			{
				p=q;
				q=r;
			}
		}
		while(r!=0);
		g=q;
	return g;
}
void StatisticsNum()
{
	int a,d,b=0;
	int c=0;
	printf("������ʮ�����ֲ�������-1����");
	do
	{
		scanf("%d",&a);
		d++;
		if(a%2==0)
		{
			b++;
		}
		if(a>0)
		{
			c+=a; 
		}
		if(d==10)break;	 
	}
	while(a!=-1);
	printf("����������Ϊ��%d,ż������Ϊ��%d",c,b); 
}
void Statisticschar()
{
	int a=0,b=0;
	char c;
	printf("�����ַ�����#�Ž�����"); 
	do
	{
		c=getchar();
		if(c>='a'&&c<='z')
		{
			b++;
		}
			a++;
	}
	while(c!='#');
	printf("�ַ�����Ϊ:%d,Сд��ĸ����Ϊ��%d",a-1,b);
}
int Statisticsmax()
{
	printf("���������ֲ�������-1����:");
	int a,c,max=0;
	do
	{
		scanf("%d",&a);
		if(max<=a)max=a;	
	}
	while(a!=-1);
	printf("���ֵΪ��%d",max);
	return max;
}
void apple()
{
	const double price=0.8;
	int num1=2,num2=0;
	double charge;
	while(num1<=100)
	{
		charge=num1*price;
		num2++;
		printf("��%d�죺%d��ƻ����%fԪ\n",num2,num1,charge);
		num1=num1*2-1;	
	}
}
void Count()
{
	const double EMS=1.0e-5;
	int n=2;
	double e=2.0,b=1.0;
	int a=1,i=1,d=2;
	while(1)
	{
		for(i=1;i<=n;i++)
		{
			a*=i;	
		} 
		e=e+1.0/a;
		d++;
		printf("a=%d\n",a);
		printf("e=%f\n",e);
		printf("%f-1.0/%d=%f\n",b,a,b-1.0/a);
		if(b-1.0/a<=EMS)
		{
			printf("e=%f,���ۼ�����=%d\n",e,d);
			break;
		}
		b=1.0/a;
		a=1;
		n++;
	}
}
int Pattern()
{
	int n;
	printf("����������(����Ϊ����)��\n");
	scanf("%d",&n); 
	char ch='*';
	int i=1,j1=1,j2=1,j3=1,j4=1;
	int a=0,b=2,c=0,d=0,e=0,f=0,g=0;
	a=n;
	if(n%2!=0)
	{
		f=1;
		for(i=1;i<=n;i++)
		{
			if(a>=1)
			{
				for(j1=1;j1<=a;j1++)
				{
					printf("%c",ch);
				}
				printf("\n");
				if(a!=1)
				{
					d+=1;
					for(j3=1;j3<=d;j3++)
					{
						printf(" ");
					}
					c++;
				}
				a-=2;continue;
			}
			if(a==-1)
			{
				e=a+4+g;
				c-=1;
				//printf("c=%d,e=%d\n",c,e);
				for(j4=1;j4<=c;j4++)
				{
					printf(" ");
				}
				for(j2=1;j2<=e;j2++)
				{
					printf("%c",ch);
				}
				g+=2;
				printf("\n");
				//printf("c=%d,e=%d\n",c,e);
			}
		}
	}else
	{
		f=0;
	}
	return f;
}
int perfectnum1(int x)
{
	int i,b=0,a=0;
	for(i=1;i<x;i++)
	{
		if(x%i==0)
		{
			a=a+i;
		}
	}
	if(x==a)
	{
		b=a;
	}
	return b;
}
void perfectnum()
{
	int a=1;
	int sum=0,i;
	for(i=1;i<=1000;i++)
	{
		sum=sum+perfectnum1(i);
		if(perfectnum1(i)!=0)
		{
			if(a)
			{
				printf("%d",perfectnum1(i));
				a--;
			}else
			{
				printf("+%d",perfectnum1(i));
			}
		}
	}
	printf("=%d\n",sum);
}
void perfectnum2()
{
	int i=1,a=2,b=0,c=1,d=1;
	for(a=2;a<=1000;a++)
	{
		for(i=1;i<a;i++)
		{
			if(a%i==0)
			{
				b=b+i;
			}
			
		}
		//printf("a=%d,b=%d\n",a,b);
		if(a==b)
		{
			for(d=1;d<a;d++)
			{
				if(a%d==0)
				{
					if(c)
					{
						printf("\n%d=%d",a,d);
						c--;
					}else
					{
						printf("+%d",d);
					}
				}
			}
			c++;
			printf("\n");
		}
		b=0;
	}
}
int DaffordiNum()
{
	int num1,num2,num3,num4=0;
	int a=100;
	while(a<1000)
	{
		num1=a/100;
		num2=(a%100)/10;
		num3=(a%100)%10;
		if(a==(num1*num1*num1+num2*num2*num2+num3*num3*num3))
		{
			printf("%d\t",a);
			num4++;
		}
		a++;
	}
	printf("\n");
	return num4;
}
void GetBall()
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
}
int MathLearn()
{
	int a,b,z,c,n;
	int answer=0,x=0;
	int y=0;
	int d=0;
	srand(time(0));
	n=(rand()%10)+5;
	for(z=0;z<n;z++)
	{
			a=rand()%11;
			b=rand()%11;
			c=rand()%4;
			if(c==1&&a-b<0)
			{
				z--;
				continue;
			}else
			{
				if(c==3&&a%b!=0)
				{
					z--;
					continue;
				}else
				{
						switch(c)
					{
						case 0:d=a+b;printf("%d+%d=",a,b);break;
						case 1:d=a-b;printf("%d-%d=",a,b);break;
						case 2:d=a*b;printf("%d*%d=",a,b);break;
						case 3:d=a/b;printf("%d/%d=",a,b);break; 
					}
					scanf("%d",&answer);
					if(answer==d)
					{
						printf("\nRight!\n");
					}else
					{
						for(x=1;x<=2;x++)
						{
							printf("\nNot Correct!Try again:");
							scanf("%d",&answer);
							if(answer==d)
							{
								printf("\nRight!\n");
								break;
							}
						}
						if(x==3)
						{
							y++;
						}
					}
				}
			}
	}
	printf("\n������%d��\n",y);			
	return y;
}
int menu()
{
	int iselect;
	printf("\n************************\n");
	printf("\n�����������躯��ָ����ţ�");
	printf("\n 1:���к����������Լ��"); 
	printf("\n 2:���к�����StatisticsNum");
	printf("\n 3:���к�����Statisticschar"); 
	printf("\n 4:���к�����Statisticsmax"); 
	printf("\n 5:���к�����ƻ������");
	printf("\n 6:���к�������������e"); 
	printf("\n 7:���к�����������ͼ��"); 
	printf("\n 8:���к�����������1"); 
	printf("\n 9:���к�����������2");
	printf("\n 10���к�������ӡˮ�ɻ���");
	printf("\n 11���к�����ȡ�򷽰�"); 
	printf("\n 12���к�����������ϰ����"); 
	printf("\n 0:�˳���"); 
	printf("\n************************\n");
	printf("����������ѡ�");
	scanf("%d",&iselect);
	return iselect; 
}

