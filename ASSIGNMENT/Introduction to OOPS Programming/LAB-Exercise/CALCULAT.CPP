#include <iostream>
#include <conio.h>

class Calculator {
public:
    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    double multiply(double a, double b) {
        return a * b;
    }

    double divide(double a, double b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Error! Division by zero not allowed.";
            return 0;
        }
    }
};

void main() {

    clrscr();
    cout << "Calculator calc";

    double num1 = 20, num2 = 5;

    cout << "Numbers: " << num1 << " and " << num2;

    cout << "Addition: " << calc.add(num1, num2);
    cout << "Subtraction: " << calc.subtract(num1, num2);
    cout << "Multiplication: " << calc.multiply(num1, num2);
    cout << "Division: " << calc.divide(num1, num2);

    getch();
}
