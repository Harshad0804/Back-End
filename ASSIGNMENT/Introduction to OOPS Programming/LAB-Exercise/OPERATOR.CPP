#include<iostream.h>
#include<conio.h>

void main()
{
	clrscr();

	int a=10,b=5;

	cout<<"\n'a = 10 & b = 5'";

	//Arithmetic operators :
	cout<<"\n\nArithmetic Oprators : ";
	cout<<"\na+b = "<<(a+b);
	cout<<"\na-b = "<<(a-b);
	cout<<"\na*b = "<<(a*b);
	cout<<"\na/b = "<<(a/b);
	cout<<"\na%b = "<<(a%b);

	//Relational Operators :
	cout<<"\n\nRelational Operators : ";
	cout<<"\na==b : "<<(a==b);
	cout<<"\na!=b : "<<(a!=b);
	cout<<"\na>b : "<<(a>b);
	cout<<"\na<b : "<<(a<b);
	cout<<"\na>=b : "<<(a>=b);
	cout<<"\na<=b : "<<(a<=b);

	cout<<"\n";

	//Logical Oprators :
	cout<<"\nLogical Operators :";
	cout<<"\n(a>b) && (b>0) : "<<((a>b) && (b>0));
	cout<<"\n(a>b) || (b<0) : "<<((a>b) || (b<0));
	cout<<"\n!(a==b) : "<<(!(a==b));

	//Bitwise Operators :
	cout<<"\n\nBitwise Operators :";
	cout<<"\na & b = "<<(a&b);
	cout<<"\na | b = "<<(a | b);
	cout<<"\na ^ b = "<<(a^b);
	cout<<"\n~a = "<<(~a);
	cout<<"\na << 1 = "<<(a << 1);
	cout<<"\na >> 1 = "<<(a >> 1);

	getch();
}