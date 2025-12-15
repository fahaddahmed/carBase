#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * @brief Adds a new car to the linked list
 * @param headLL The head of the linked list
*/
void addNewCar(struct car **headLL)
{
    struct car *carToAdd = (struct car *)malloc(sizeof(struct car));
    struct car *last = *headLL;
    int sum = 0;

    if (carToAdd == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    // Get the car details from the user
    printf("Enter the car model: ");
    scanf("%s", carToAdd->model);
    printf("Enter the car type: ");
    scanf("%s", carToAdd->type);
    printf("Enter its year of manufacture: ");
    scanf("%d", &carToAdd->year);
    printf("Enter its price: ");
    scanf("%lf", &carToAdd->price);

    // Generate a unique carId based on the model and type
    // This follows the specifications of generating the car Id according to the assignment
    for (int i = 0; carToAdd->model[i] != '\0'; i++)
    {
        sum += carToAdd->model[i];
    }
    carToAdd->carId = sum + strlen(carToAdd->type);


    // This section of the code ensures that the Car Id is unique as per the assignment specifications
    srand(time(NULL));
    while (lookForCarId(*headLL, carToAdd->carId) != -1)
    {
        carToAdd->carId += rand() % 999 + 1;
    }

    // Print the generated carId
    printf("Your computer-generated carId is %d\n", carToAdd->carId);
    carToAdd->nextCar = NULL;

    // Append the new car to the linked list by either setting it as the head or traversing to the end then adding it
    if (*headLL == NULL)
    {
        *headLL = carToAdd;
        return;
    }
    while (last->nextCar != NULL)
    {
        last = last->nextCar;
    }
    last->nextCar = carToAdd;
}


