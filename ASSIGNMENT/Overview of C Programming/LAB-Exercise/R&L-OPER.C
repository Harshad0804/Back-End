#include<stdio.h>
#include<conio.h>

void main()
{
	int a,b;
	clrscr();
	printf("\nEnter A : ");
	scanf("%d",&a);
	printf("\nEnter B : ");
	scanf("%d",&b);
	printf("\n------------------------------------");
	printf("\nRelational Operators");
	printf("\n------------------------------------");
	printf("\na == b : %d",a==b);
	printf("\na != b : %d",a!=b);
	printf("\na > b : %d",a>b);
	printf("\na < b : %d",a<b);
	printf("\na >= b : %d",a>=b);
	printf("\na <= b : %d",a<=b);

	printf("\n------------------------------------");
	printf("\nLogical Operators");
	printf("\n------------------------------------");

	printf("\n(a && b) : %d",(a && b));
	printf("\n(a || b) : %d",(a || b));
	printf("\n!(a) : %d",!a);
	printf("\n!(b) : %d",!b);

	getch();
}