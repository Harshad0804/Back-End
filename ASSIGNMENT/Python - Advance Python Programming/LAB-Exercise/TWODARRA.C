#include<stdio.h>
#include<conio.h>

void main()
{
	int arr[3][3];
	int i,j,sum = 0;
	clrscr();

	printf("\nEnter elements of 3x3 Matrix :\n ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	printf("\nMatrix elements are : \n ");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d",arr[i][j]);
			sum += arr[i][j];
		}
		printf("\n");
	}

	printf("\nSum of all elements in 3x3 Matrix = %d",sum);

	getch();
}