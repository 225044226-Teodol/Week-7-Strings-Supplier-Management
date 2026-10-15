#include <stdio.h>
#include <string.h>

// ========== Function Declarations ==========
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void addSupplier();
void displaySuppliers();
void searchSupplier();

// ========== Global variables for suppliers ==========
char name[5][100];
char email[5][100];
char phone[5][30];
char town[5][50];
int count = 0;   // number of suppliers

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
        getchar();   // clear the enter key

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

            case 5: // Add Supplier
                addSupplier();
                break;

            case 6: // Display Suppliers
                displaySuppliers();
                break;

            case 7: // Search Supplier
                searchSupplier();
                break;

            case 8:
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 8);

    return 0;
}

// ========== Function Definitions ==========

void displayMenu() {
    printf("\n============================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Add Supplier\n");
    printf("6. Display Suppliers\n");
    printf("7. Search Supplier\n");
    printf("8. Exit\n");
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

void addSupplier() {
    if (count >= 5) {
        printf("\nMaximum of 5 suppliers reached.\n");
        return;
    }

    printf("\nEnter supplier name: ");
    fgets(name[count], sizeof(name[count]), stdin);
    name[count][strcspn(name[count], "\n")] = 0;

    printf("Enter email: ");
    fgets(email[count], sizeof(email[count]), stdin);
    email[count][strcspn(email[count], "\n")] = 0;

    printf("Enter phone: ");
    fgets(phone[count], sizeof(phone[count]), stdin);
    phone[count][strcspn(phone[count], "\n")] = 0;

    printf("Enter town: ");
    fgets(town[count], sizeof(town[count]), stdin);
    town[count][strcspn(town[count], "\n")] = 0;

    count++;
    printf("\nSupplier added successfully! (Total: %d)\n", count);
}

void displaySuppliers() {
    int i;

    if (count == 0) {
        printf("\nNo suppliers added yet.\n");
        return;
    }

    printf("\n--- ALL SUPPLIERS ---\n");
    for (i = 0; i < count; i++) {
        printf("\nSupplier %d:\n", i + 1);
        printf("Name : %s\n", name[i]);
        printf("Email: %s\n", email[i]);
        printf("Phone: %s\n", phone[i]);
        printf("Town : %s\n", town[i]);
    }
}

void searchSupplier() {
    char search[100];
    int i, found = 0;

    if (count == 0) {
        printf("\nNo suppliers added yet.\n");
        return;
    }

    printf("\nEnter supplier name to search: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;

    for (i = 0; i < count; i++) {
        if (strcmp(search, name[i]) == 0) {
            printf("\nSupplier found!\n");
            printf("Name : %s\n", name[i]);
            printf("Email: %s\n", email[i]);
            printf("Phone: %s\n", phone[i]);
            printf("Town : %s\n", town[i]);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Supplier not found.\n");
    }
}