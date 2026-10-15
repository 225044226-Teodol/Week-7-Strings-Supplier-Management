#include <stdio.h>
#include <string.h>

int main() {
    char name[100] = "";
    char email[100] = "";
    char phone[30] = "";
    char town[50] = "";
    char search[100];
    int choice;
    int hasSupplier = 0;   // 0 = no supplier yet, 1 = supplier added

    do {
        printf("\n================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();   // clear the enter key left by scanf

        switch (choice) {
            case 1:
                printf("\nEnter supplier name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;

                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0;

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = 0;

                hasSupplier = 1;
                printf("\nSupplier added successfully!\n");
                break;

            case 2:
                if (hasSupplier == 0) {
                    printf("\nNo supplier added yet.\n");
                } else {
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    printf("Name : %s\n", name);
                    printf("Email: %s\n", email);
                    printf("Phone: %s\n", phone);
                    printf("Town : %s\n", town);
                }
                break;

            case 3:
                if (hasSupplier == 0) {
                    printf("\nNo supplier added yet.\n");
                } else {
                    printf("\nEnter supplier name to search: ");
                    fgets(search, sizeof(search), stdin);
                    search[strcspn(search, "\n")] = 0;

                    if (strcmp(search, name) == 0) {
                        printf("Supplier found.\n");
                    } else {
                        printf("Supplier not found.\n");
                    }
                }
                break;

            case 4:
                if (hasSupplier == 0) {
                    printf("\nNo supplier added yet.\n");
                } else {
                    printf("\nSupplier name length: %zu\n", strlen(name));
                }
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