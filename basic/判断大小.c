#include<stdio.h>
int main()
{double a,b,c;
scanf("%lf %lf %lf",&a,&b,&c);
double max=0;
 if(a>b){if(a<c){max=c;}else{max=a;}}
 else{if(b>c){max=b;}else{max=c;}}
 printf("�������ǣ�%f",max);
 return 0;}





