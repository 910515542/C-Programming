#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
	int num;
	struct _node *next;
} Node;

Node* reverselist(Node *head)
{
	if(head == NULL || head->next == NULL)
	return head;
	Node *newh = NULL, *p = head, *temp;
	while(p!= NULL)
	{
		temp = p->next;
		//�Ƚ�����λ�ýڵ�ӵ��ϴ�ѭ����newhǰ�� 
		p->next = newh;
		//���øýڵ��Ϊ�µ���ͷ 
		newh = p;
		p = temp;
	}
	return newh;
}
 
Node* reverselist2(Node *h)
{
	Node *newh = NULL, *p = NULL;
	if(h == NULL || h->next == NULL)
	{
		return h;
	}
	//�ݹ�ﵽ�������һ���ڵ㣬����return �����������൱�ڴ�����β���������� 
	newh = reverselist2(h->next);
	h->next->next = h;//�ú���ִ����֮�������ͷ��nextû�����ǣ���ָ��ڶ����ڵ㣬������next������NULL
	//��˵�����ú������轫������ͷ��next = NULL������������ʾ�ڸ��������h->next = NULL������䡣
	//h->next = NULL; 
	return newh;
}

int main()
{
	Node *head = NULL, *last = NULL, *p = NULL, *q = NULL;
	int temp;
	
	scanf("%d", &temp);
	while(temp != -1)
	{
		p = malloc(sizeof(Node));
		p->num = temp;
		p->next = NULL;
		if(last)
		{
			last->next = p;
			last = last->next;
		}
		else
		{
			last = p;
			head = p;
		}
		scanf("%d", &temp);
	}
	p = reverselist2(head);
//	head->next = NULL;//���û��������䣬���޷���������ı��� 
	for( ; p; p = p->next)
	{
		printf("%d ", p->num);
	}
	printf("\n");
	for(p = head; p; p = q)
	{
		q = p->next;
		free(p);
	}
	return 0;
}
