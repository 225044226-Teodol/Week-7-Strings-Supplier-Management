#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char email[100];
    char phone[30];
    char town[50];

    printf("Enter supplier name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter email: ");
    fgets(email, sizeof(email), stdin);

    printf("Enter phone: ");
    fgets(phone, sizeof(phone), stdin);

    printf("Enter town: ");
    fgets(town, sizeof(town), stdin);

    // remove the newline that fgets adds
    name[strcspn(name, "\n")] = 0;
    email[strcspn(email, "\n")] = 0;
    phone[strcspn(phone, "\n")] = 0;
    town[strcspn(town, "\n")] = 0;

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", name);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    printf("\n--- STRING LENGTHS ---\n");
    printf("Supplier name length: %zu\n", strlen(name));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    return 0;
}