#ifndef __STUDENT__
#define __STUDENT__

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define StuCount 5
#define SubCount 5


extern char *cSubject[];//�γ����� 
extern int iStuNo[];//ѧ��ѧ�� 
extern int Computer[];//������ɼ� 
extern int Math[];//��ѧ�ɼ� 
extern int English[];//Ӣ��ɼ� 
extern int Chinese[];//���ĳɼ� 
extern int Physics[];//�����ɼ� 
extern int iScoreHigh[];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����߷� 
extern int iScoreLow[];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����ͷ� 
extern int iScoreAve[];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ���ƽ����
extern int iHighNo[];
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����߷�ѧ�� 
extern int iFineCount[];
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ��ƴ��������� 
extern int iFailCount[]; 
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ��Ʋ��������� 


int MenuSelect();//��ʾ������ѡ��Ĳ˵���� 
int MenuHandle();//�˵����� 
int InputData();//����ԭʼ���� 
void StaticScore();//ͳ����߷֡���ͷ֡�ƽ���֡���߷�ѧ�� 
int GetHigh(int  *Score,int *Highest);//ͳ����߷ּ���߷�ѧ�� 
int GetLow(int *Score);//ͳ����ͷ� 
int GetAve(int *Score);//ͳ��ƽ���� 
void StaticPerson();//ͳ������Ͳ��������� 
void GetFine_Fail(int *Score, int *fine, int *fail);//ͳ������Ͳ���������  
void SortByAve();//��ƽ�������� 
void DisplayStat();//��ʾ���ſγ̳ɼ��� 
void DisplaySort();//��ʾѧ���ɼ������� 
void Exchange(int *str1, int *str2);//����󽻻���Ϣ 

#endif 
