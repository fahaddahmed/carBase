#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Looks for a car with a specific model and type in the linked list
 * @param headLL The head of the linked list
 * @param key The model and type to look for
 * @return The index of the car in the linked list, or -1 if not found
 */
int lookForCarModelType(struct car *headLL, char key[100])
{
    int index = 1;
    char modelAndType[1000];

    while (headLL != NULL)
    {
        memset(modelAndType, 0, sizeof(modelAndType));

        // Concatenate the model and type of the car
        snprintf(modelAndType, sizeof(modelAndType), "%s %s", headLL->model, headLL->type);

        // Compare the concatenated string with the key and return the index if found
        if (strcmp(modelAndType, key) == 0)
        {
            return index;
        }

        // Move to the next car in the linked list
        headLL = headLL->nextCar;
        index++;
    }

    // Return -1 if the car is not found
    return -1;
}

