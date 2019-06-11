#include<stdio.h>
#include<stdlib.h>

#define stucount 3

struct _student {
	char name[20];
	int number;
	int chinese;
	int math;
	int english;
	int sumscore;
	double avescore;
} student[stucount];

int cmp(const void *a, const void *b);
void display1(struct _student student[stucount]);
void display2(struct _student student[stucount]);
void display3(struct _student student[stucount]); 

int main()
{
	int i, flag = 0;
	
	printf("�밴���¸�ʽ����ѧ����Ϣ��\n");
	printf("����   ѧ��  ����  ��ѧ  Ӣ��\n"); 
	for(i = 0; i < stucount; i++)
	{
		scanf("%s %d %d %d %d", student[i].name, &student[i].number,
		 &student[i].chinese, &student[i].math, &student[i].english);
		 student[i].avescore = (student[i].chinese + student[i].math + student[i].english) * 1.0 / 3;
		 student[i].sumscore = student[i].chinese + student[i].math + student[i].english;
	}
	qsort(student, stucount, sizeof(student[0]), cmp);
	printf("\n***************************************\n");
	printf("0.�鿴�ܷ���������ѧ��\n");
	printf("1.�鿴���Ƶ�һ�������һ��ѧ����Ϣ\n");
	printf("2.�鿴ƽ���ɼ�����\n");
	printf("-1.�˳�����\n");
	printf("\n���������ָ�");
	scanf("%d", &flag);
	while(flag != -1)
	{
		switch(flag)
		{
			case 0:display3(student);break;
			case 1:display1(student);break;
			case 2:display2(student);break;
			default :printf("�������");break;
		}
		printf("\n���������ָ�");
		scanf("%d", &flag);
	}
	return 0;
}

void display1(struct _student student[stucount])
{
	int i, pos[3][2] = { 0 };
	
	for(i = 0; i < stucount; i++)
	{
		if(student[i].chinese > student[pos[0][0]].chinese)
		{
			pos[0][0] = i;
		}
		if(student[i].chinese < student[pos[0][1]].chinese)
		{
			pos[0][1] = i;
		}
		if(student[i].math > student[pos[1][0]].math)
		{
			pos[1][0] = i;
		}
		if(student[i].math < student[pos[1][1]].math)
		{
			pos[1][1] = i;
		}
		if(student[i].english > student[pos[2][0]].english)
		{
			pos[2][0] = i;
		}
		if(student[i].english < student[pos[2][1]].english)
		{
			pos[2][1] = i;
		}
	}
	printf("��Ŀ    ��һ��    ���һ��\n");
	printf("����    %s(%d��)    %s(%d��)\n", student[pos[0][0]].name, student[pos[0][0]].chinese,
										student[pos[0][1]].name, student[pos[0][1]].chinese);
	printf("��ѧ    %s(%d��)    %s(%d��)\n", student[pos[1][0]].name, student[pos[1][0]].math,
										student[pos[1][1]].name, student[pos[1][1]].math);
	printf("Ӣ��    %s(%d��)    %s(%d��)\n", student[pos[2][0]].name, student[pos[2][0]].english,
										student[pos[2][1]].name, student[pos[2][1]].english);
}

int cmp(const void *a, const void *b)
{
	struct _student *aa = (struct _student*)a;
	struct _student *bb = (struct _student*)b;
	return aa->avescore > bb->avescore?0:1;
}

void display2(struct _student student[stucount])
{
	int i;
	
	printf("����        ѧ��  ����  ��ѧ  Ӣ��\n");
	for(i = 0; i < stucount; i++)
	{
		printf("%s(%.2f��)  %4d  %4d  %4d  %4d\n", student[i].name, student[i].avescore, student[i].number,
										student[i].chinese, student[i].math, student[i].english);
	}
}

void display3(struct _student student[stucount])
{
	int i, pos1 = 0, pos2 = 0;
	
	for(i = 0; i < stucount; i++)
	{
		if(student[i].sumscore > student[pos1].sumscore)
		{
			pos1 = i;
		}
		else
		{
			pos2 = i;
		}
	}
	printf("              ����      ѧ��  ����  ��ѧ  Ӣ��\n");
	printf("��߷�  %s(%d��)  %4d  %4d  %4d  %4d\n", student[pos1].name, student[pos1].sumscore, student[pos1].number,
												student[pos1].chinese, student[pos1].math,
												student[pos1].english);
	printf("��ͷ�  %s(%d��)  %4d  %4d  %4d  %4d\n", student[pos2].name, student[pos2].sumscore, student[pos2].number,
												student[pos2].chinese, student[pos2].math,
												student[pos2].english);
}
