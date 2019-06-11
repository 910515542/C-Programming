#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *srcFile, *destFile;
	int ch;
	
	/*********Found************/
	if (argc != 3)
	{
		printf("�����������.\n");	
		exit(1);
	}
	
	/*********Found************/
	if ((srcFile = fopen(argv[1], "rb")) == NULL)
	{
		printf("�޷���Դ�ļ� %s\n", argv[1]);
		exit(2);
	}
	
	if ((destFile = fopen(argv[2], "wb")) == NULL)
	{
		fclose(srcFile);
		printf("�޷���Ŀ���ļ� %s\n", argv[2]);
		exit(3);
	}
	
	while ((ch = fgetc(srcFile))  !=  EOF)
	{
		fputc(ch, destFile);
	}
	printf("succeful to copy a file!\n");
	fclose(srcFile);
	fclose(destFile);
	
	return 0;
}