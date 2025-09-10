#include <iostream.h>
#include <conio.h>

void main() 
{
    clrscr();

    int marks;

    cout << "Enter student's marks (0-100): ";
    cin >> marks;

    if (marks >= 90) 
    {
        cout << "Grade: A+";
    }
    else if (marks >= 75) 
    {
        cout << "Grade: A";
    }
    else if (marks >= 60) 
    {
        cout << "Grade: B";
    }
    else if (marks >= 45) 
    {
        cout << "Grade: C";
    }
    else if (marks >= 33) 
    {
        cout << "Grade: D";
    }
    else 
    {
        cout << "Grade: Fail";
    }

    getch();
}