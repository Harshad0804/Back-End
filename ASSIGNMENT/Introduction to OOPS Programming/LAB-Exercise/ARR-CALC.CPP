#include<iostream.h>
#include<conio.h>

void main() 
{
    clrscr();

    int n, i;
    int arr[50];   
    int sum = 0;
    float avg;

    cout << "\nEnter number of elements (max 50): ";
    cin >> n;

    cout << "\nEnter " << n << " integers: " <<;
    for (i = 0; i < n; i++) 
    {
        cin >> arr[i];
	sum = sum + arr[i];
    }

    avg = (float)sum / n;  

    cout << "\nSum = " << sum;
    cout << "\nAverage = " << avg;

    getch();
}