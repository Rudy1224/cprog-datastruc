#include <stdio.h>

void main(void)
{
	int a[3][3];
	int i,j,sum=0;
	printf("�������: \n");
	for(i=0; i<3; i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d", *(a+i)+j);
		}
	}
	printf("\n����Ϊ:\n");
	for (i=0; i<3; i++)
	{
		for (j=0;j<3;j++)
		{
			printf("%4d", *(*(a+i)+j));
		}
		printf("\n");
	}
	for (i=0;i<3;i++)
	{
		sum += *(*(a+i)+i);
	}
	printf("�Խ���Ԫ�غ�Ϊ%d��\n", sum);
}

