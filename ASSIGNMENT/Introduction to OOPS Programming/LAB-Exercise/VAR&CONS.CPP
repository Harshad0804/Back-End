#include <iostream.h>
#include <conio.h>
#include <string.h>

void main()
{
    const double PI = 3.14159;

    int age = 20;
    float height = 5.9f;
    double radius = 7.5;
    char grade = 'A';
    char name[20] = "Harshad";  // use C-style string in Turbo C++
    int isStudent = 1;          // use int instead of boolean (0 = false, 1 = true)

    int nextYearAge = age + 1;
    double areaOfCircle = PI * radius * radius;
    float increasedHeight = height + 0.1f;

    clrscr(); // clear screen

    cout << "Name: " << name << endl;
    cout << "Age: " << age << " (Next year: " << nextYearAge << ")" << endl;
    cout << "Height: " << height << " (After increase: " << increasedHeight << ")" << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is Student? " << (isStudent ? "Yes" : "No") << endl;
    cout << "Radius of circle: " << radius << endl;
    cout << "Area of circle (using constant PI): " << areaOfCircle << endl;

    getch(); // wait for key press
}
