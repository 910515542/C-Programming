#include"student.h"

int iStuNo[StuCount];//ѧ�� 
int iComputer[StuCount];//������ɼ� 
int iMath[StuCount];//��ѧ 
int iEnglish[StuCount];//Ӣ�� 
int iChinese[StuCount];//���� 
int iPhysics[StuCount];//����ɼ� 


int iScoreHigh[SubCount];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����߷� 
int iScorelow[SubCount];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����ͷ� 
int iScoreAve[SubCount];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ���ƽ����
int iHighNo[SubCount];
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����߷�ѧ�� 
int iFineCount[SubCount];
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ��ƴ��������� 
int iFailCount[SubCount]; 
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ��Ʋ��������� 

void main(void)
{
	freopen("c:\\test\\test1.txt", "r", stdin);
	int option;
	int quit;
	
	
	printf("\n\n\n\n\n");
	printf("\t\t************************************************\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*    ѧ���ɼ��������                          *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*             �����������......               *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t*                                              *\n");
	printf("\t\t************************************************\n");
	getche();
	while(1)
	{
		option = MenuSelect();//�õ��û�ѡ��Ĳ˵���� 
		quit = MenuHandle(option);//���в˵�ִ�У�ֱ���û��˳�����case 6��quit = 1�� 
		if(quit == 1)break;
	}
}

int MenuSelect(void)
{
	int option;
	int input;

	
	system("cls");
	printf("\n\n****************************************\n");
	printf("\t1.	����ԭʼ����\n");
	printf("\t2.	ͳ����߷֡���ͷ֡�ƽ���ֺ���߷�ѧ��ѧ��\n");
	printf("\t3.	ͳ������Ͳ���������\n");
	printf("\t4.	��ƽ�������򣬲���ʾ������\n");
	printf("\t5.	��ʾѧ���ɼ�ͳ�Ʊ�\n");
	printf("\t6.	�˳�����\n");
	printf("\n\t���ֶ�Ӧ����ѡ����ѡ��1-6��	");
	
	
	while(1)
	{
		input = scanf("%d",&option);
		if(input != 1)
		{
			printf("\n\t ���������ѡ1-6��");
			fflush(stdin); 
		}
		else
		{
			if((option<1) || (option>6))
			{
				printf("\n\t ѡ�������ѡ1-6��");
			}
			else break; 
		}
	} 
	return option;
} 

int MenuHandle(int option)
{
	int quit = 0;
	switch(option)
	{
		case 1:if(InputData() == 0)//����ѧ������Ƴɼ� 
		{
			printf("\n\n�������ݴ��󣬳����˳�");
			fflush(stdin);
			quit = 1; 
		}
		else
		{
			printf("\nOK!\t����������룬�����������......");
			getche();
			break; 
		}
		
		case 2:StaticScore();     //���Ʒ���ͳ�� 
			   printf("\nOK!\t��ɷ���ͳ�ƣ������������......");
			   getche();
			   break;
			   
		case 3:StaticPerson();   //ͳ�������벻�������� 
			   printf("\nOK!\t�������ͳ�ƣ������������......");
			   getche();
			   break;
			   
		case 4:SortByAve();     //��ƽ�������򣬲���ʾ������ 
			   DisplaySort();
			   printf("\nOK!\t������򣬰����������......");
			   getche();
			   break;
			   
		case 5:DisplayStat();   //��ʾ�ɼ�ͳ�Ʊ� 
			   printf("\n�����������......");
			   getche();
			   break;
			   
		case 6:quit = 1;       ///�������� 
		       break; 
	}
	return quit;
}
