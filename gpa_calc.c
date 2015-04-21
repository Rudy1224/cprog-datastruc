#include <stdio.h>
#include <stdlib.h>
#define N 10

struct Student
	{
		int id;
		char name[20];
		int score1, score2, score3;
		float gpa;
	} list[N];
int temp[N];

void save(void)
{
	FILE *fp;
	int i;
	if ((fp = fopen("Student List.txt", "w")) == NULL){
		printf("Cannot open file.\n");
		return;}
	for (i=0; i<N; i++){
		fprintf(fp, "%02d\t%s\t%d\t%d\t%d\t%.2f\n", list[temp[i]].id, list[temp[i]].name, list[temp[i]].score1, list[temp[i]].score2, list[temp[i]].score3, list[temp[i]].gpa);}
	fclose(fp);
}

void main(void)
{
	int i,j,k;
	for (i=0;i<N;i++)
	{
		scanf("%d %s %d %d %d", &list[i].id, list[i].name, &list[i].score1, &list[i].score2, &list[i].score3);
		list[i].gpa = (list[i].score1+list[i].score2+list[i].score3)/3.0;
		temp[i]=i;
	}
	for (i=0; i<N; i++)
	{
		for (j=0; j<N-i-1; j++)
		{
			if (list[temp[j]].gpa<list[temp[j+1]].gpa)
			{
				k = temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=k;
			}		
		}}
	printf("\nID\tName\tScore1\tScore2\tScore3\tGPA\n");
	for (i=0; i<N; i++)
	{		
		printf("%02d\t%s\t%d\t%d\t%d\t%.2f\n", list[temp[i]].id, list[temp[i]].name, list[temp[i]].score1, list[temp[i]].score2, list[temp[i]].score3, list[temp[i]].gpa);
	}
	save();
}