#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints the menu for the user to choose from
*/
void printMenu()
{
    printf("\nMenu:\n");
    printf("1. Add data on a new car\n");
    printf("2. Load data on cars from a given text file\n");
    printf("3. Print data of all cars\n");
    printf("4. Print data of the nth car\n");
    printf("5. Search car data based on carId\n");
    printf("6. Search car data based on model and type\n");
    printf("7. Count the total number of cars in the list\n");
    printf("8. Sort the cars in the list based on carId\n");
    printf("9. Remove data of the nth car\n");
    printf("10. Remove all car data\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
}

/**
 * @brief Main function to run the program
*/
int main()
{
    struct car *head = NULL;
    int choice;
    while (1)
    {
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            addNewCar(&head);
            break;
        }
        case 2:
        {
            char fileName[MAX_LENGTH];
            printf("Enter filename: ");
            scanf("%s", fileName);
            loadCarData(&head, fileName);
            break;
        }
        case 3:
        {
            printAll(head);
            break;
        }
        case 4:
        {
            int n;
            printf("Enter the position: ");
            scanf("%d", &n);
            printOne(head, n);
            break;
        }
        case 5:
        {
            // Get the carId from the user
            int carId;
            printf("Enter car ID: ");
            scanf("%d", &carId);
            int pos = lookForCarId(head, carId);
            printf("\n");

            // If the car is found, print its details
            if (pos != -1)
            {
                printOne(head, pos);
            }
            else
            {
                printf("Car not found.\n");
            }
            break;
        }
        case 6:
        {
            // These variables are used to store the model and type entered by the user
            char userModel[49];
            char userType[50];
            char modelType[100];

            printf("Enter the model and type (separated by a space): ");

            // Read the model and type from the user, then concatenate them into a single string
            scanf("%48s %49s", userModel, userType);
            snprintf(modelType, sizeof(modelType), "%s %s", userModel, userType);

            // Search for the car based on the model and type
            int pos = lookForCarModelType(head, modelType);
            printf("\n");

            // If the car is found, print its details
            if (pos != -1)
            {
                printOne(head, pos);
            }
            else
            {
                printf("Car not found.\n");
            }
            break;
        }
        case 7:
        {
            printf("Total number of cars: %d\n", countCars(head));
            break;
        }
        case 8:
        {
            sortCarId(&head);
            break;
        }
        case 9:
        {
            int n;
            printf("Enter the position of the car to remove: ");
            scanf("%d", &n);
            oneLessCar(&head, n);
            break;
        }
        case 10:
        {
            char c;
            printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
            scanf(" %c", &c);

            // If the user confirms, remove all car data
            if (c == 'y' || c == 'Y')
            {
                noMoreCars(&head);
            }

            break;
        }
        case 11:
        {
            printf("Exiting...\n");
            return 0;
        }
        default:
        {
            printf("Invalid choice. Please try again.\n");
            break;
        }
        }
    }
    return 0;
}

