#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b;

	clrscr();

	printf("\nEnter A :");
	scanf("%d",&a);

	printf("\nEnter B :");
	scanf("%d",&b);

	printf("\n\nTHE ARITHEMATIC OPERATOR");

	printf("\nA + B = %d",a+b);
	printf("\nA - B = %d",a-b);
	printf("\nA / B = %d",a/b);
	printf("\nA * B = %d",a*b);
	printf("\nA %% B = %d",a%b);

	getch();
}