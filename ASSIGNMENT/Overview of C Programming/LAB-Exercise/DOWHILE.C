#include<stdio.h>
#include<conio.h>

void main()
{
	int n,sum=0;
	clrscr();
	printf("\nEnter N Number : ");
	scanf("%d",&n);
	do
	{
		sum=sum+n;
		n--;
	}while(n>0);
	printf("\nSum : %d",sum);

	getch();

}