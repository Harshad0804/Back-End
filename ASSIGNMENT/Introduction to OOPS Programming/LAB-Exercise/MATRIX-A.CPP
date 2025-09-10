#include<iostream.h>
#include<conio.h>

void main() 
{
    clrscr();

    int A[2][2], B[2][2], C[2][2];
    int i, j;

    cout << "\nEnter elements of first 2x2 matrix:\n";
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements of second 2x2 matrix:\n";
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            cin >> B[i][j];
        }
    }

    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nResultant Matrix after Addition:\n";
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            cout << C[i][j] << " ";
        }
        cout <<;
    }

    getch();
}