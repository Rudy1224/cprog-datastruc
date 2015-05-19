#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
	char name[3];
	int	id,rank,c1,c2,c3;
	float avg;
	struct student *next;
}STU;

void display(STU *head)
{
	STU *p=NULL;
	p=head;
    while(p!=NULL)
    {
        printf("%-5d %-5s %-5d %-5d %-5d %-5.2f\n",p->id,p->name,p->c1,p->c2,p->c3,p->avg);
        p=p->next;
	}
}

STU *del(STU *head,int num)
{
	STU *p1=NULL,*p2=NULL,*p3=NULL;
	if(head==NULL)
		printf("No data!\n");
	else
	{
		p1=head;
		while(p1->next!=NULL)
		{
			if(p1->id==num)
				break;
			p2=p1;
			p1=p1->next;
		}
		if(p1->id==num)
		{
            if(p1==head)
			{
				head=head->next;
				p3=head;
			}
			else if(p1=NULL)
			{
				p2->next=p1->next;
				p3=p1->next;
			}
			while(p3!=NULL)
			{
				p3->id--;
				p3=p3->next;
			}
			free(p1);
			printf("Data deleted\n");
		}
		else
			printf("No data!\n");
	}
	return head;
}

STU *insert(STU *head,STU *p)
{
	STU *p1=NULL,*p2=NULL;
	if(head==NULL)
	{
		head=p;
		p->next=NULL;
	}
	else
	{
		p1=head;
		while(p1->next!=NULL)
		{
			if(p->avg>p1->avg)
				break;
			p2=p1;
			p1=p1->next;
		}
		if(p1==head&&p1->avg<p->avg)
		{
			p->next=head;
			head=p;
		}
		else if(p1->avg<p->avg)
		{
			p->next=p1;
			p2->next=p;
		}
		else
{
			p1->next=p;
			p->next=NULL;
		}
	}
	return head;
}

int main(void)
{
	int i;
	char c=0;
	STU *head=NULL,*p=NULL;
	FILE *fp;
	fp=fopen("St.txt","r");
	while(!feof(fp))
	{
	    p=(STU *)malloc(sizeof(STU));
		p->next=NULL;
		fscanf(fp,"%d %d %s %d %d %d %f\n",&p->rank,&p->id,p->name,&p->c1,&p->c2,&p->c3,&p->avg);
		head=insert(head,p);
		p=p->next;
	}
	fclose(fp);
	display(head);
	while(c!='e')
	{
		printf("Please enter a command:\n");
		printf("Enter \"i\" to add one record.\n");
		printf("Enter \"d\" to delete the record.\n");
		printf("Enter \"e\" to save and exit.\n");
		scanf("%c",&c);
		if(c=='d')
		{
			printf("Enter the id to be deleted: ");
			scanf("%d",&i);
			head=del(head,i);
		}
		else if(c=='i')
		{
			p=(STU *)malloc(sizeof(STU));
			p->next=NULL;
		    printf("id:\n");
			scanf("%d",&p->id);
			printf("name:\n");
			scanf("%s",p->name);
			printf("c1:\n");
			scanf("%d",&p->c1);
			printf("c2:\n");
			scanf("%d",&p->c2);
			printf("c3:\n");
			scanf("%d",&p->c3);
			p->avg=((float)p->c1+p->c2+p->c3)/3;
			head=insert(head,p);
			printf("Data added\n");
		}
		else
			continue;
		printf("\n");
		display(head);
	}
	fp=fopen("St.txt","w+");
	p=head;
	i=1;
	while(p!=NULL)
	{
		fprintf(fp,"%d %5d %5s %5d %5d %5d %5f\n",i,p->id,p->name,p->c1,p->c2,p->c3,p->avg);
		p=p->next;
		i++;
	}
	fclose(fp);
	return 0;
}
