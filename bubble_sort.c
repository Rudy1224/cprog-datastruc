#include <stdio.h>

void bubble_sort(int a[])
{
	int i, j, temp;
	for (i=0; i<4; i++)
	{
		for (j=0; j<4-i; j++)
		{
			if (a[j]>a[j+1])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}}}}

void main(void)
{
	int i;
	int list[5];
	for (i=0; i<5; i++)
	{
		scanf("%d", &list[i]);
	}
	bubble_sort(list);
	for (i=0; i<5; i++)
	{
		printf("%d ", list[i]);
	}
}