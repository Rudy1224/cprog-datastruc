#include<stdio.h>
#define LEN 20

struct inf
{
	int data[LEN];
    int *head;
	int *tail;
	int n;
}q;

void q_insert(struct inf *q)
{
	if (q->n==LEN)
		printf("The QUEUE is FULL\n");
	else
	{
		(q->n)++;
		printf("Please Enter Number:\n");
		if (q->tail-q->data==LEN-1)
		    q->tail=q->data;
		else
		    q->tail++;
		    scanf("%d",q->tail);
	}
}

void q_delete(struct inf *q)
{
	if (q->n==0)
	    printf("The QUEUE is EMPTY\n");
	else
	{
	    (q->n)--;
	    if (q->head-q->data==LEN-1)
	        q->head=q->data;
	    else
	        (q->head)++;
	}
}

void q_check(struct inf *q)
{
	if (q->n==LEN)
	    printf("The QUEUE is FULL\n");
	else if (q->n==0)
		printf("The QUEUE is EMPTY\n");
}

int main()
{
    int i, *p;
	q.head=q.data;
	q.n=0;
	q.tail=q.data+LEN-1;
	do
	{
		printf("Please Enter:\n	i:insert\n	o:delete\n	c:check\n	e:exit\n");
		switch (getchar())
		{
		case'i':q_insert(&q);getchar();break;
		case'o':q_delete(&q);getchar();break;
		case'c':q_check(&q);getchar();break;
		case'e':return(0);
		}
	    i=0;
	    p=q.head;
	    while(i<q.n){printf("%d",*(p+i++));}
	    putchar('\n');
	}while(1);
}