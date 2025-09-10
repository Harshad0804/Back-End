#include <iostream.h>
#include <conio.h>

void main() 
{
    clrscr();

    int secretNumber = 45;  
    int guess;

    cout << "Guess the number between 1 and 100!";


    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! Try again.";
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again.";
        }
        else {
            cout << "Congratulations! You guessed the correct number.";
        }

    } while (guess != secretNumber);

    getch();
}