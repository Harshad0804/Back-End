#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	int num1,num2,sum;

	cout<<"\nEnter First Number : ";
	cin>>num1;

	cout<<"\nEnter Second Number : ";
	cin>>num2;

	sum = num1 + num2;

	cout<<"\nThe sum of "<<num1<<" and "<<num2<<" is : "<<sum;

	getch();
}