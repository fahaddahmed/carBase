#include "header.h"

/**
 * @brief Counts the number of cars in the linked list
 * @param headLL The head of the linked list
 */
int countCars(a3Car *headLL)
{
    int count = 0;
    for (a3Car *temp = headLL; temp != NULL; temp = temp->nextCar)
    {
        count++;
    }

    return count;
}

