#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();
	//Implicit
	int num1=10;
	float num2=5.5;
	float result1=num1+num2;

	cout<<"\nImplicit Conversion Example :";
	cout<<"\nNum1 (int) = "<<num1;
	cout<<"\nNum2 (float) = "<<num2;
	cout<<"\nResult (float) = "<<result1;

	cout<<"\n";

	//Explicit

	double pi=3.14159;
	int approx = (int)pi;

	cout<<"\nExplicit Conversion Example :";
	cout<<"\npi (double) = "<<pi;
	cout<< "\nAfter Casting to int = "<<approx;

	getch();
}