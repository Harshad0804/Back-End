#include<stdio.h>
#include<conio.h>
#include<dos.h>

void main()
{
	int i;
	clrscr();
	printf("\nUsing Continue and Break statement :");
	for(i=1;i<=10;i++)
	{
		if(i==3)
		{
			continue;
		}
		delay(1000);
		if(i==5)
		{
			break;
		}
		printf("\n%d",i);
	}
	getch();
}