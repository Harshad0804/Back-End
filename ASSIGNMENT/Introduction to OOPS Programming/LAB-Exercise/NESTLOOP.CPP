#include <iostream.h>
#include <conio.h>

void main()
{
    clrscr();

    int rows;

    cout << "\nEnter number of rows for the triangle: ";
    cin >> rows;

    cout << "\nRight-Angled Triangle:\n";

   
    for (int i = 1; i <= rows; i++) {
       
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;  
    }

    getch();
}