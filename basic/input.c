#include"student.h"

int iStuNo[StuCount];//ѧ��ѧ�� 
int Computer[StuCount];//������ɼ�
int Math[SubCount];//��ѧ�ɼ� 
int English[StuCount];//Ӣ��ɼ� 
int Chinese[StuCount];//���ĳɼ� 
int Physics[StuCount];//����ɼ� 

int InputData(void)
{
	int i;
	int n = 0;//��Ϊ���ر��� 
	int flag = 0;  //�б���������ı�־
	
	
	system("cls");
	printf("\n\n����������ʾ��˳��͸�ʽ����ԭʼ���ݣ� \n");
	printf("  ѧ��ѧ�� ������ɼ� ��ѧ�ɼ� Ӣ��ɼ� ���ĳɼ� �����ɼ�\n");
	for(i = 0; i < StuCount; i++)
	{
		printf("%2d:", i + 1);
		flag = scanf("%d %d %d %d %d %d", &iStuNo[i], &Computer[i], &Math[i], &English[i], &Chinese[i], &Physics[i]);
		if(flag != 6)
		{
			fflush(stdin);
			break;
		}
		else
		{
			n = 1;
		}
		//����ɼ� 
	}
	return n;		
} 
