#include<stdio.h>
#include<conio.h>

void main()
{
	int i;
	clrscr();

	// Using While Loop
	printf("\nNumbers from 1 to 10 using While Loop");

	i = 1;
	while (i<=10)
	{
		printf("%d",i);
		i++;
	}

	//Using For Loop
	printf("\nNumber from 1 to 10 using For Loop");
	for(i=1 ; i<=10 ; i++)
	{
		printf("%d",&i);
	}

	//Using Do-While Loop
	printf("\nNumbers from 1 to 10 using Do-While Loop");
	i=1;
	do
	{
		printf("%d",&i);
		i++;
	}while(i <= 0);
	getch();

}