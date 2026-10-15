#include <stdio.h>
#include <string.h>

int main() {
    char name[5][100];
    char email[5][100];
    char phone[5][30];
    char town[5][50];
    char search[100];

    int count = 0;   // how many suppliers we have so far
    int choice;
    int i;
    int found;

    do {
        printf("\n================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();   // clear the enter key

        switch (choice) {
            case 1:
                if (count >= 5) {
                    printf("\nMaximum of 5 suppliers reached.\n");
                } else {
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
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo suppliers added yet.\n");
                } else {
                    printf("\n--- ALL SUPPLIERS ---\n");
                    for (i = 0; i < count; i++) {
                        printf("\nSupplier %d:\n", i + 1);
                        printf("Name : %s\n", name[i]);
                        printf("Email: %s\n", email[i]);
                        printf("Phone: %s\n", phone[i]);
                        printf("Town : %s\n", town[i]);
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\nNo suppliers added yet.\n");
                } else {
                    printf("\nEnter supplier name to search: ");
                    fgets(search, sizeof(search), stdin);
                    search[strcspn(search, "\n")] = 0;

                    found = 0;
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
                break;

            case 4:
                if (count == 0) {
                    printf("\nNo suppliers added yet.\n");
                } else {
                    printf("\n--- NAME LENGTHS ---\n");
                    for (i = 0; i < count; i++) {
                        printf("%s : %zu characters\n", name[i], strlen(name[i]));
                    }
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