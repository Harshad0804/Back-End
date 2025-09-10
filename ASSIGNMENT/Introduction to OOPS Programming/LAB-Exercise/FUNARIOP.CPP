#include <iostream.h>
#include <conio.h>

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
 {
    return a - b;
 }

int multiply(int a, int b)
{
    return a * b;
}

float divide(int a, int b)
{
    if (b != 0)
	return (float)a / b;
    else
	return 0;
}

void main()
{
    clrscr();

    int num1, num2, choice;
    float result;

    cout << "\nEnter first number: ";
    cin >> num1;

    cout << "\nEnter second number: ";
    cin >> num2;

    cout << "\nChoose operation:\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
	case 1:
	    result = add(num1, num2);
	    cout << "Result = " << result;
	    break;
	case 2:
	    result = subtract(num1, num2);
	    cout << "Result = " << result;
	    break;
	case 3:
	    result = multiply(num1, num2);
	    cout << "Result = " << result;
	    break;
	case 4:
	    if (num2 != 0) {
		result = divide(num1, num2);
		cout << "Result = " << result;
	    } else {
		cout << "Error! Division by zero not allowed.";
	    }
	    break;
	default:
	    cout << "Invalid choice!";
    }

    getch();
}