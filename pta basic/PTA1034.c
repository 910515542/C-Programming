#include<stdio.h>

typedef long long ll;

int getnum(ll a, ll b);//�����Լ�� 
void output(ll a, ll b);//��� 

int main()
{
	ll a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	output(a1, b1);printf(" + ");output(a2, b2);printf(" = ");output(a1 * b2 + b1 * a2, b1 * b2);
	printf("\n");
	output(a1, b1);printf(" - ");output(a2, b2);printf(" = ");output(a1 * b2 - b1 * a2, b1 * b2);
	printf("\n");
	output(a1, b1);printf(" * ");output(a2, b2);printf(" = ");output(a1 * a2, b1 * b2);
	printf("\n");
	output(a1, b1);printf(" / ");output(a2, b2);printf(" = ");
	//���ڳ������������a1 * b2������Ҫ��a2�ĸ��Ż���b2�� 
	if(a2 < 0)
	{
		a2 *= -1;
		b2 *= -1;
	}
	if(b1 * a2 == 0)
	{
		printf("Inf");
	}
	else
	{
		output(a1 * b2, b1 * a2);
	}
	printf("\n");
	return 0;
}

int getnum(ll a, ll b)
{
	return b == 0 ?a : getnum( b, a % b );
} 
void output(ll a, ll b)
{
	ll flag = a, symbol;
	if(a < 0)
	{
		a *= (-1);
		printf("(-");
	}
	symbol = getnum(a, b);
	a /= symbol;
	b /= symbol;
	if(a % b == 0)
	printf("%lld", a / b);
	else
	{
		if(a > b)
		{
			printf("%lld ", a / b);
		}
		printf("%lld/%lld", a % b, b);
	}
	if(flag < 0)
	printf(")");
} 
