#include"student.h"

void DisplayStat(void)
{
	int i;
	system("cls");
	printf("\n\n\n");
	printf("�� Ŀ ��߷� ��ͷ� ƽ���� �������� ���������� ��߷�ѧ��ѧ��\n");
	
	for(i = 0; i < SubCount; i++)
	{
		printf("%-6s %6d %6d %6d %8d %10d\t%d\n",
		cSubject[i], iScoreHigh[i], iScoreLow[i],
		iScoreAve[i], iFineCount[i], iFailCount[i], iHighNo[i]);					
	}
}

void DisplaySort(void)
{
	int i;
	system("cls");
	printf("\n\n\n");
	printf("ѧ��ѧ�� ������ɼ� ��ѧ�ɼ� Ӣ��ɼ� ���ĳɼ� �����ɼ�\n");
	for(i = 0; i < StuCount; i++)
	{
		printf("%8d %10d %8d %8d %8d %8d\n",
		iStuNo[i], Computer[i], Math[i], English[i], Chinese[i], Physics[i]);
	}
}
