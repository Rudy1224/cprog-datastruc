#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define QElemType int
typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return 1;
}

int ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return 1;
}

int QueueEmpty(SqQueue Q)
{ 
	if (Q.front==Q.rear)
	{
		return 1;
	}
	else
		return 0;
}

int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

int GetHead(SqQueue Q,QElemType *e)
{
	if(Q.front==Q.rear)
		return 0;
	*e=Q.data[Q.front];
	return 1;
}

int EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)
		return 0;
	Q->data[Q->rear]=e;			
	Q->rear=(Q->rear+1)%MAXSIZE;
	return 1;
}

int DeQueue(SqQueue *Q)
{
	if (Q->front == Q->rear)			
		return 0;			
	Q->front=(Q->front+1)%MAXSIZE;	
	return 1;
}

int display(SqQueue Q)
{ 
	int i;
	i=Q.front;
	while((i+Q.front)!=Q.rear)
	{
		printf("%d ",Q.data[i]);
		i=(i+1)%MAXSIZE;
	}
	return 1;
}

int main()
{
	char cmd='i';
	int x;
	SqQueue Q;
	InitQueue(&Q);
	while(cmd!='q')
	{
		printf("\nchoose function[i/e/q]:");
		scanf("%s",&cmd);
		if (cmd=='i')
		{
			printf("insert number:");
		    scanf("%d",&x);
		    EnQueue(&Q, x);
		    display(Q);
		}
		else if (cmd=='e')
		{
			DeQueue(&Q);
			display(Q);
		}
		else
		{
			printf("choose among i, e and q!");
		}
	}
	return 0;
}
