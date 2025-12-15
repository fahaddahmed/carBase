#include "header.h"
#include <stdbool.h>

/**
 * @brief Sorts the linked list by carId
 * @param headLL The head of the linked list
 * @note Uses bubble sort
 */
void sortCarId(struct car **headLL)
{
    bool hasSwapped;
    struct car *carOne;
    struct car *carTwo = NULL;

    if (*headLL == NULL)
    {
        return;
    }

    do
    {
        hasSwapped = false;
        carOne = *headLL;

        while (carOne->nextCar != carTwo)
        {
            if (carOne->carId > carOne->nextCar->carId)
            {
                // Temporarily store the values of the first car
                int tempId = carOne->carId;
                int tempYear = carOne->year;
                double tempPrice = carOne->price;
                char tempModel[MAX_LENGTH];
                strcpy(tempModel, carOne->model);
                char tempType[MAX_LENGTH];
                strcpy(tempType, carOne->type);


                // Swap the values of the first car with the second car
                carOne->carId = carOne->nextCar->carId;
                carOne->nextCar->carId = tempId;
                carOne->year = carOne->nextCar->year;
                carOne->nextCar->year = tempYear;
                carOne->price = carOne->nextCar->price;
                carOne->nextCar->price = tempPrice;
                strcpy(carOne->model, carOne->nextCar->model);
                strcpy(carOne->nextCar->model, tempModel);
                strcpy(carOne->type, carOne->nextCar->type);
                strcpy(carOne->nextCar->type, tempType);

                // Set the flag to true to indicate that a swap has occurred
                hasSwapped = true;
            }
            carOne = carOne->nextCar;
        }

        // Now that the last car is in the correct position, set it as the second car for the next iteration
        carTwo = carOne;
    } while (hasSwapped);
}

