#include<stdio.h>
#include<conio.h>

void star()
{
	printf("\n**************************************");
}

void line()
{
	printf("\n--------------------------------------");
}


void main()
{
	int choice, quantity, more;
	float total=0;

	clrscr();

	do
	{
		star();
		//DIsplay For Menu
		printf("\nMenu Card : ");
		printf("\n1. Pizza        - Rs.299");
		printf("\n1. Burger       - Rs.199");
		printf("\n3. Pasta        - Rs.179");
		printf("\n4. Sandwich     - Rs.189");
		printf("\n5. FrenchFries  - Rs.129");
		line();

		//Take User Choice
		printf("\nEnter Your Choice (From 1-5) : ");
		scanf("%d",&choice);
		line();

		//Take Quantity
		printf("\nENter Your Food Quantity : ");
		scanf("%d",&quantity);
		line();
		line();

		//Calculate cost According Choice
		switch(choice)
		{
			case 1 :
				total = total + 299 * quantity;
				printf("\nAdded %d Pizza(s).",quantity);
				break;
			case 2 :
				total = total + 199 * quantity;
				printf("\nAdded %d Burger(s).",quantity);
				break;
			case 3 :
				total = total + 179 * quantity;
				printf("\nAdded %d Pasta(s).",quantity);
				break;
			case 4 :
				total = total + 189 * quantity;
				printf("\nAdded %d Sandwich(s).",quantity);
				break;
			case 5 :
				total = total + 129 * quantity;
				printf("\nAdded %d French-Fries(s).",quantity);
				break;
			default :
				printf("\nYou Added Nothing / Invalid Choice");
		}
		star();
		star();

		//Ask if You Want More
		printf("\nDo you want to order more? (1 = Yes/0 = No) : ");
		scanf("%d",&more);
		line();

	}while(more == 1);
	//Final bill
	printf("\nYour Final Bill");
	star();
	printf("\nTotal Amount to Pay = Rs. %.2f", total);
	star();
	printf("\nThank You...!     Visit Again...!");
	star();

	getch();
}

