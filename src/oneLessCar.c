#include "header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Removes a car from the linked list
 * @param headLL The head of the linked list
 * @param whichOne The index of the car to remove
 */
void oneLessCar(struct car **headLL, int whichOne)
{
    struct car *temp = *headLL;

    if (*headLL == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    // Invalid position case
    if (whichOne < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    // If the head is to be removed
    if (whichOne == 1)
    {
        *headLL = temp->nextCar;
        free(temp);
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < whichOne - 1; i++)
    {
        temp = temp->nextCar;
    }

    // Validate the position (if the position is greater than the number of cars in the list)
    if (temp == NULL || temp->nextCar == NULL)
    {
        printf("Position %d does not exist.\n", whichOne);
        return;
    }

    // Delete the node at the position
    struct car *next = temp->nextCar->nextCar;
    free(temp->nextCar);
    temp->nextCar = next;
}

