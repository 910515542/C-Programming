#include"student.h"

int iScoreHigh[SubCount];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����߷� 
int iScoreLow[SubCount];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����ͷ� 
int iScoreAve[SubCount];//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ���ƽ����
int iHighNo[SubCount];
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ�����߷�ѧ�� 
int iFineCount[SubCount];
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ��ƴ��������� 
int iFailCount[SubCount]; 
		//�Լ��������ѧ��Ӣ����ġ������˳���Ÿ��Ʋ��������� 

void StaticScore(void)
{ 
	int SubjectNo[] = {0, 1, 2, 3, 4};//�������ſγ� 
	//ͳ�Ƽ������Ŀ�����Ϣ 
	iHighNo[SubjectNo[0]] = GetHigh(Computer,&iScoreHigh[SubjectNo[0]]);
	iScoreLow[SubjectNo[0]] = GetLow(Computer);
	iScoreAve[SubjectNo[0]] = GetAve(Computer); 
	//ͳ����ѧ��Ŀ�����Ϣ  
	iHighNo[SubjectNo[1]] = GetHigh(Math,&iScoreHigh[SubjectNo[1]]);
	iScoreLow[SubjectNo[1]] = GetLow(Math);
	iScoreAve[SubjectNo[1]] = GetAve(Math);
	//ͳ��Ӣ���Ŀ�����Ϣ 
	iHighNo[SubjectNo[2]] = GetHigh(English,&iScoreHigh[SubjectNo[2]]);
	iScoreLow[SubjectNo[2]] = GetLow(English);
	iScoreAve[SubjectNo[2]] = GetAve(English);
	//ͳ�����Ŀ�Ŀ�����Ϣ
	iHighNo[SubjectNo[3]] = GetHigh(Chinese,&iScoreHigh[SubjectNo[3]]);
	iScoreLow[SubjectNo[3]] = GetLow(Chinese);
	iScoreAve[SubjectNo[3]] = GetAve(Chinese); 
	//ͳ��������Ŀ�����Ϣ
	iHighNo[SubjectNo[4]] = GetHigh(Physics,&iScoreHigh[SubjectNo[4]]);
	iScoreLow[SubjectNo[4]] = GetLow(Physics);
	iScoreAve[SubjectNo[4]] = GetAve(Physics); 
}

void StaticPerson(void)
{
	int SubjectNo[] = {0, 1, 2, 3, 4};//�������ſγ� 
	int fine, fail;
	//ͳ�Ƽ���������벻�������� 
	GetFine_Fail(Computer,&fine,&fail);
	iFineCount[SubjectNo[0]] = fine;
	iFailCount[SubjectNo[0]] = fail;
	//ͳ����ѧ�����벻�������� 
	GetFine_Fail(Math, &fine, &fail);
	iFineCount[SubjectNo[1]] = fine;
	iFailCount[SubjectNo[1]] = fail;
	//ͳ��Ӣ�������벻�������� 
	GetFine_Fail(English, &fine, &fail);
	iFineCount[SubjectNo[2]] = fine;
	iFailCount[SubjectNo[2]] = fail;
	//ͳ�����������벻�������� 
	GetFine_Fail(Chinese, &fine, &fail);
	iFineCount[SubjectNo[3]] = fine;
	iFailCount[SubjectNo[3]] = fail;
	//ͳ�����������벻�������� 
	GetFine_Fail(Physics, &fine, &fail);
	iFineCount[SubjectNo[4]] = fine;
	iFailCount[SubjectNo[4]] = fail;
}

void GetFine_Fail(int *Score, int *fine, int *fail)
{
	int i;
	*fine = *fail = 0;
	for(i = 0; i < StuCount; i++)
	{
		if(Score[i] >= 90)
		{
			*fine+=1;
		}
		else
		{
			if(Score[i] < 60)
			{
				*fail+=1;
			}
		}
	}
}

int GetHigh(int *Score, int *Highest)
{
	int i = 0,HighNo = 0;
	int max = Score[0];
	for(i = 0; i < StuCount; i++)
	{
		if(max < Score[i])
		{
			max = Score[i];
			HighNo = i;
		}
	}
	*Highest = max;
	return iStuNo[HighNo];
}

int GetLow(int *Score)
{
	int i, min = Score[0];
	for(i = 0; i < StuCount; i++)
	{
		if(min > Score[i])
		{
			min = Score[i];
		}
	}
	return min;
}

int GetAve(int *Score)
{
	int i, sum = 0;
	int Ave = 0;
	for(i = 0; i < StuCount; i++)
	{
		sum += Score[i];
	}
	Ave = sum/StuCount;
	return Ave;
}

