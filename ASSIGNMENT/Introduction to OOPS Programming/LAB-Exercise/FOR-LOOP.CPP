#include <iostream.h>
#include <conio.h>

void main() 
{
    clrscr();

    int num;

    cout << "Enter a number to display its multiplication table: ";
    cin >> num;

    cout << "\nMultiplication Table of " << num << ":\n";

    for (int i = 1; i <= 10; i++) 
    {
        cout << num << " x " << i << " = " << (num * i) << endl;
    }

    getch();
}