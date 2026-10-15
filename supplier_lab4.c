#include <stdio.h>
#include <string.h>

int main() {
    char original[100];
    char backup[100];

    printf("Enter supplier name: ");
    fgets(original, sizeof(original), stdin);

    // remove newline
    original[strcspn(original, "\n")] = 0;

    // copy the string
    strcpy(backup, original);

    printf("\nOriginal : %s\n", original);
    printf("Backup   : %s\n", backup);

    return 0;
}