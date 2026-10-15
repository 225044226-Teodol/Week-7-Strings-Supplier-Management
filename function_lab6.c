#include <stdio.h>

// function declaration
int searchEmployee(int id, int ids[], int size);

int main() {
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int size = 5;
    int id, position;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    position = searchEmployee(id, employeeIDs, size);

    if (position != -1) {
        printf("Employee found at position %d.\n", position);
    } else {
        printf("Employee not found.\n");
    }

    return 0;
}

// function definition
int searchEmployee(int id, int ids[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i;   // return the position
        }
    }

    return -1;   // not found
}