#include <stdio.h>
#include <string.h>

int main() {
    char supplier1[] = "ABC Office Supplies";
    char supplier2[] = "Namibia Stationery";
    char search[100];

    printf("Enter supplier name to search: ");
    fgets(search, sizeof(search), stdin);

    // remove the newline
    search[strcspn(search, "\n")] = 0;

    if (strcmp(search, supplier1) == 0 || strcmp(search, supplier2) == 0) {
        printf("Supplier found.\n");
    } else {
        printf("Supplier not found.\n");
    }

    return 0;
}