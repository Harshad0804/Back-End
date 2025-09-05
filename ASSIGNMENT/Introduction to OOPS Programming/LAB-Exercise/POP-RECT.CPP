#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int length,width,area;

	cout<<"\nEnter length of Rectangle : ";
	cin>>length;

	cout<<"\nEnter width of Rectangle : ";
	cin>>width;

	area = length * width;

	cout<<"\nArea of Rectangle = "<<area;

	getch();
}