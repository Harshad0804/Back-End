#include<stdio.h>
#include<conio.h>

void main()
{
	int num,month;
	clrscr();

	printf("\n\nEnter a Number : ");
	scanf("%d",&num);

	if(num % 2 == 0)
	{
		printf("\n%d is Even Number.",num);
	}
	else
	{
		printf("\n%d is Odd Number.",num);
	}


	printf("\n\n\nEnter A number For Month(Between 1 to 12) : ");
	scanf("%d",&month);

	switch (month)
	{
		case 1 :
			printf("\nJanuary");
			break;
		case 2 :
			printf("\nFebruary");
			break;
		case 3 :
			printf("\nMarch");
			break;
		case 4 :
			printf("\nApril");
			break;
		case 5 :
			printf("\nMay");
			break;
		case 6 :
			printf("\nJune");
			break;
		case 7 :
			printf("\nJuly");
			break;
		case 8 :
			printf("\nAugust");
			break;
		case 9 :
			printf("\nSeptember");
			break;
		case 10 :
			printf("\nOctober");
			break;
		case 11 :
			printf("\nNovember");
			break;
		case 12 :
			printf("\nDecember");
			break;
		default :
			printf("\nThe Choosen Number is not between 1 to 12");
	}
	getch();
}

