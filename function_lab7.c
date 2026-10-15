#include <stdio.h>

// function declarations
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main() {
    int choice;
    float amount, vat;
    float basic, housing, transport, gross;
    float revenue, expenses, balance;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int id, position;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Calculate VAT
                printf("\nEnter amount: ");
                scanf("%f", &amount);
                vat = calculateVAT(amount);
                printf("VAT: %.2f\n", vat);
                break;

            case 2: // Calculate Salary
                printf("\nBasic salary: ");
                scanf("%f", &basic);
                printf("Housing allowance: ");
                scanf("%f", &housing);
                printf("Transport allowance: ");
                scanf("%f", &transport);
                gross = calculateSalary(basic, housing, transport);
                printf("Gross salary: %.2f\n", gross);
                break;

            case 3: // Calculate Budget
                printf("\nEnter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                    printf("SURPLUS\n");
                else if (balance < 0)
                    printf("DEFICIT\n");
                else
                    printf("BALANCED\n");
                break;

            case 4: // Search Employee
                printf("\nEnter employee ID: ");
                scanf("%d", &id);
                position = searchEmployee(id, employeeIDs, 5);

                if (position != -1)
                    printf("Employee found at position %d.\n", position);
                else
                    printf("Employee not found.\n");
                break;

            case 5:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// ========== Function Definitions ==========

void displayMenu() {
    printf("\n==================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("==================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;
        }
    }
    return -1;
}