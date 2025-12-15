#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Removes all cars from the linked list
 * @param headLL The head of the linked list
 */
void noMoreCars(struct car **headLL)
{
    struct car *currCar = *headLL;
    struct car *nextCar;

    // Simply iterate through the linked list and free each node
    while (currCar != NULL)
    {
        nextCar = currCar->nextCar;
        free(currCar);
        currCar = nextCar;
    }

    // Set the head to NULL and indicate that the linked list is empty
    *headLL = NULL;
    printf("All removed. Linked list is now empty.\n");
}

