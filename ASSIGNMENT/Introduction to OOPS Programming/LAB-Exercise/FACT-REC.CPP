#include <iostream.h>
#include <conio.h>

long factorial(int n) 
{
    if (n == 0 || n == 1)   
        return 1;
    else
        return n * factorial(n - 1);  
}

void main() 
{
    clrscr();

    int num;
    long result;

    cout << "Enter a number to find its factorial: ";
    cin >> num;

    if (num < 0) 
    {
        cout << "Factorial is not defined for negative numbers.";
    }
    else 
    {
        result = factorial(num);
        cout << "Factorial of " << num << " = " << result;
    }

    getch();
}