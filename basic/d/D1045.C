#include <stdio.h>

struct Student
{
	char No[11];
	int Score;
};

int FindMaxScore(struct Student stu[], int n);

int main(void)
{
	struct Student stus[3] = {{"2008030201", 89}, {"2008030202", 92}, {"2008030203", 78}};
	int k;
	
	k = FindMaxScore(stus, 3);
	printf("�ɼ���ߵ�ѧ����Ϣ��:\n");
	printf("ѧ��\t\t�ɼ�\n");
	printf("%s\t%d\n", stus[k].No, stus[k].Score);
	
	return 0;
}

/*********Found************/
int FindMaxScore(struct Student stu[], int n)
{
	int i, max, k=0;
	
	max = stu[k].Score;	
	for (i=1; i<n; i++)
	{
		/*********Found************/
		if (max < stu[i].Score) 
		{
			k = i;
			max = stu[k].Score;
		}
	}

	return k;
}