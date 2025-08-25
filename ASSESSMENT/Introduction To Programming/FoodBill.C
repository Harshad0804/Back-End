#include <stdio.h>
#include <conio.h>

int main() {
    int choice, quantity, more;
    float total = 0;

    clrscr(); // clear screen (Turbo C specific)

    printf("=====================================\n");
    printf("       WELCOME TO FOOD CENTER        \n");
    printf("=====================================\n");

    do {
        // Display Menu
        printf("\nMENU CARD:\n");
        printf("1. Pizza       - Rs.199\n");
        printf("2. Burger      - Rs.99\n");
        printf("3. Pasta       - Rs.149\n");
        printf("4. Sandwich    - Rs.79\n");
        printf("5. FrenchFries - Rs.59\n");

        // Take user choice
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        // Take quantity
        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate cost according to choice
        switch(choice) {
            case 1: total += 199 * quantity;
                    printf("Added %d Pizza(s).\n", quantity);
                    break;
            case 2: total += 99 * quantity;
                    printf("Added %d Burger(s).\n", quantity);
                    break;
            case 3: total += 149 * quantity;
                    printf("Added %d Pasta(s).\n", quantity);
                    break;
            case 4: total += 79 * quantity;
                    printf("Added %d Sandwich(es).\n", quantity);
                    break;
            case 5: total += 59 * quantity;
                    printf("Added %d French Fries.\n", quantity);
                    break;
            default: printf("Invalid choice! Please select from 1-5.\n");
        }

        // Ask if want more
        printf("\nDo you want to order more? (1 = Yes / 0 = No): ");
        scanf("%d", &more);

    } while(more == 1);

    // Final bill
    printf("\n=====================================\n");
    printf("             FINAL BILL               \n");
    printf("=====================================\n");
    printf("Total Amount to Pay = Rs. %.2f\n", total);
    printf("=====================================\n");
    printf("    THANK YOU! VISIT AGAIN 😊        \n");
    printf("=====================================\n");

    getch(); // wait for key press in Turbo C
    return 0;
}
