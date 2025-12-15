#include "header.h"

/**
 * @brief Looks for a car with a specific carId in the linked list
 * @param headLL The head of the linked list
 * @param key The carId to look for
 * @return The position of the car in the linked list, or -1 if not found
 */
int lookForCarId(struct car *headLL, int key)
{
    int index = 1;

    // Iterate through the linked list and return the index if the carId is found
    for (struct car *currCar = headLL; currCar != NULL; currCar = currCar->nextCar)
    {
        if (currCar->carId == key)
        {
            return index;
        }
        index++;
    }

    return -1;
}

