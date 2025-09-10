#include<iostream.h>
#include<conio.h>
#include<string.h>

void main() 
{
    clrscr();

    char str[50];
    int i, j, len;
    int isPalindrome = 1;  

    cout << "\nEnter a string: ";
    cin >> str;

    len = strlen(str);

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
	if (str[i] != str[j])
	{
	    isPalindrome = 0;
	    break;
	}
    }

    if (isPalindrome == 1)
	cout << str << " is a Palindrome.";
    else
	cout << str << " is NOT a Palindrome.";

    getch();
}