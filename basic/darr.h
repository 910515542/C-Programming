#ifndef __array__
#define __array__


#include<stdlib.h>
#include<stdio.h>

#define block 20

typedef struct {
	int *array;
	int size;
} Array;

Array array_creat(int init_size);//�ṩ���� 
void array_free(Array *a);//�ͷ�malloc�ڴ� 
int array_size(const Array *a);//�õ�Ŀǰ�����С 
int* array_at(Array *a, int index)//�����������鵥Ԫ 
void array_inflate(Array *a, int more_size);//����ռ�仯 

#endif
