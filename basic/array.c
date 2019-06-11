#include "array.h"


//typedef struct {
//	int *array;
//	int size;
//} Array;

int main()
{
	int i = 0;
	int number = 0;
	Array a = array_creat(10);
	array_free(&a);
	printf("%d\n", array_size());
	while(number != -1)
	{
		scanf("%d", &number);
		if(number != -1)
		{
			*array_at(&a, i) = number;
			i++;
		}
	}
	printf("%d\n", *array_at(&a, 0));
	return 0;
}

Array array_creat(int init_size)//�ṩ����
{
	Array a;
	a.array = (int *)malloc(sizeof(int) * init_size);
	a.size = init_size;
	return a;	
} 

void array_free(Array *a)//�ͷ�malloc�ڴ� 
{
	free(a->array);
	a->size = 0;
	a->array = NULL;
}

int array_size(const Array *a)//�õ�Ŀǰ�����С 
{
	return a->size;
}

int* array_at(Array *a, int index)//�����������鵥Ԫ 
{
	if(index > a->size)
	{
		array_flate(&a, (index/block + 1) * 20 - a->size);
	}
	return &(a->array[index]);
}

void array_inflate(Array *a, int more_size)//����ռ�仯 
{
	int *p = (int *)malloc(sizeof(int) * (a->size + more_size));
	int i;
	for(i = 0; i < a->size; i++)
	{
		p[i] = a->array[i];
	}
	free(a->array);
	p = a->array;
	a->size += more_size;
}

