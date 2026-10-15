#include <stdio.h>

// function declaration
void displayMenu();

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Goodbye!\n");
        } else if (choice < 1 || choice > 4) {
            printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

// function definition
void displayMenu() {
    printf("\n==================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}