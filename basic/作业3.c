#include<stdio.h>
void  prog3_1()
{
	double x=2.5;
	double y=4.7;
	int z=7;
	int a=12;
	printf("x+z%3*(int)(x+y)%2/4=%f\n",x+z%3*(int)(x+y)%2/4);
	printf("���ʽ1ֵ=%d\n",a+=a);
	a=12;
	printf("���ʽ2ֵ=%d\n",a*=2+3);
	a=12;
	printf("���ʽ3ֵ=%d\n",a%=(5%2));
	a=12;
	printf("���ʽ4ֵ=%d\n",a+=a-=a*=a);
 } 
 
 #define STR1 "computer"
 #define STR2 "english"
 void prog7_5()
 {
 	int a=5,b=7;
 	float x=67.8546f,y=-789.124f;
 	long n=1234567;
 	unsigned int u=65535; 
 	printf("\n#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-\n");
 	printf("a,b:%3d%3d\n",a,b);
 	printf("x,y:%f,%f\n",x,y);
 	printf("x,y:%-15f,%f\n",x,y);
 	printf("x,y:%8.2f,%f\n",x,y);
 	printf("x,y:%e,%e\n",x,y);
 	printf("n,n,n:%d,%o,%x\n",n,n,n);
 	printf("u,u,u:%d,%o,%x\n",u,u,u);
 	printf("STR1,STR2:%s,%5.3s\n",STR1,STR2);
 }	
 
 int mathlearn()
 {	int a,b,c;
 	printf("\n�������һ��������\n");
 	scanf("%d",&a);
 	printf("������ڶ�������:\n");
 	scanf("%d",&b);
 	printf("%d+%d=\n",a,b);
 	scanf("%d",&c);
 	if(a+b==c){
 		printf("�ش���ȷ��\n");
	 }else{
		printf("�𰸴��󣬼���Ŭ��Ӵ��\n"); 
	 }
 }
 
 void prog9_1()
 {
 	int a,b,c,d,e;
 	printf("\n��ֱ�����a��b��c��d��ֵ��\n");
 	scanf("%d %d %d %d",&a,&b,&c,&d);
 	e=a-a*b/(c+d);
 	printf("���ʽֵΪ��%d\n",e);
 }
 int main()
 {
 	prog3_1();
 	prog7_5();
 	mathlearn();
 	prog9_1();
 	return 0;
 }
