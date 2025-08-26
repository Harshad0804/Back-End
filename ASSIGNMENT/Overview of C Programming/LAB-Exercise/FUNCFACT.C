#include<stdio.h>
#include<conio.h>

int factorial(int n);

void main()
{
	int num,fact;
	clrscr();
	printf("\nEnter a name : ");
	scanf("%d",&num);

	fact = factorial(num);

	printf("\nFactorial of %d is %d",num,fact);

	getch();
}

int factorial(int n)
{
	int i,result = 1;
	for(i=1;i<=n;i++)
	{
		result = result * i;
	}
	return result;
}