#include <stdio.h>
#include <stdlib.h>

// Employee structure
typedef struct {
    char name[50];
    char jobTitle[50];
    double hourlyWage;
} Employee;

// Function prototypes
void printEmployeeList(Employee employees[], int numEmployees);
double calculateTotalWages(Employee employees[], int numEmployees);

int main() {
    // Pre-populated list of employees
    Employee employees[5] = {
        {"Brittany Avalos-Ortiz", "Manager", 15.50},
        {"Jade Jones", "Assistant", 12.75},
        {"Shakhai Mole", "Clerk", 10.25},
        {"LJ Jackson", "Intern", 8.50},
        {"Sean Kim", "Supervisor", 14.00}
    };

    int choice;
    double totalWages;

    do {
        // Display menu
        printf("\nOptions:\n");
        printf("1. Print list of employees\n");
        printf("2. Calculate total wages\n");
        printf("3. Exit application\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printEmployeeList(employees, 5);
                break;
            case 2:
                totalWages = calculateTotalWages(employees, 5);
                printf("Total wages for the week: $%.2f\n", totalWages);
                break;
            case 3:
                printf("Exiting application.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                // Clear input buffer
                while(getchar() != '\n');
        }
    } while (1);

    return 0;
}

// Function to print employee list
void printEmployeeList(Employee employees[], int numEmployees) {
    printf("\nEmployee List:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Name: %s, Job Title: %s, Hourly Wage: $%.2f\n", 
               employees[i].name, employees[i].jobTitle, employees[i].hourlyWage);
    }
}

// Function to calculate total wages
double calculateTotalWages(Employee employees[], int numEmployees) {
    double totalWages = 0.0;
    double hoursWorked;

    for (int i = 0; i < numEmployees; i++) {
        printf("Enter total hours worked for %s: ", employees[i].name);
        scanf("%lf", &hoursWorked);
        if (hoursWorked < 0) {
            printf("Invalid input. Hours worked cannot be negative.\n");
            i--; // Try again for the same employee
            continue;
        }
        totalWages += hoursWorked * employees[i].hourlyWage;
    }

    return totalWages;
}
