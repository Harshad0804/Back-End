#include <iostream.h>
#include <conio.h>

class Rectangle
{
	int length, width;

	public:

	void input() {
	cout << "Enter length of rectangle: ";
	cin >> length;
	cout << "Enter width of rectangle: ";
	cin >> width;
}

	int calculateArea()
	{
		return length * width;
	}

	void display()
	{
		cout << "Area of rectangle = " << calculateArea();
	}
};

void main()
{
	clrscr();

	Rectangle rect;
	rect.input();
	rect.display();

	getch();
}