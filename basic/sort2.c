#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void StringBubbleSort(char *MyStrings[], int iCount,int iSortType)
{
  	int i,j, flag; 
  	char  **pp, *temp = NULL;
  	pp = MyStrings;
  	for(i = 2; i < iCount + 2; i++)
  	{
  		printf("%s\n", pp[i]);
	}
	printf("\n");
  	for(i = 1; i < iCount; i++)
 	{
	   	for(j = 2; j < iCount + 2 - i; j++)      
	   	{
	   		flag = strcmp(pp[j], pp[j + 1]);
	    	if(iSortType) //��С�������� 
	    	{ 
	     		if(flag > 0) 
	     		{ 
	      			temp = pp[j]; 
	      			pp[j] = pp[j+1];  
	     			pp[j+1] = temp; 
	    		} 
	    	} 
	    	else //�Ӵ�С���� 
	    	{ 
	    		 if(flag < 0) 
	     		{  
	     			temp = pp[j]; 
	      			pp[j] = pp[j+1]; 
	      			pp[j+1] = temp; 
	     		} 
	    	} 
	   }
	}
}

int main(int argc, char *argv[])
{ 
	int i,iSortType; 
	if (argc < 4)
	{  //�����������������ַ��� 
		printf("Parameters are not enough. Order Format:\n"); 
		printf("sort type string1 string2 string...\n"); 
		return 0; 
	} 
	iSortType = atoi(argv[1]);    //��1������ ����ʽ 
	StringBubbleSort(argv, argc - 2,iSortType);  //������ 
	for (i=2; i<argc; i++)//��ʾ������
	{
   		printf("%s\n", argv[i]);
   	}
	return 1;
}
