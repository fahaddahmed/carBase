#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * @brief Loads car data from a file into the linked list
 * @param headLL The head of the linked list
 * @param fileName The name of the file to load data from
 */
void loadCarData(struct car **headLL, char fileName[MAX_LENGTH])
{
    FILE *file = fopen(fileName, "r");
    struct car *currentCar, *tail = NULL;
    char currentLine[256];
    int carId, year;
    double price;

    if (!file)
    {
        printf("Failed to open file: %s\n", fileName);
        return;
    }

    // Read each line from the file, line by line
    while (fgets(currentLine, sizeof(currentLine), file) != NULL)
    {
        // Allocate memory for the new car
        currentCar = (struct car *)malloc(sizeof(struct car));
        if (!currentCar)
        {
            printf("Memory allocation failed.\n");
            fclose(file);
            return;
        }

        // Since the file is formatted as "carId,model,type,year,price", parse the line accordingly
        if (sscanf(currentLine, "%d,%[^,],%[^,],%d,%lf", &carId, currentCar->model, currentCar->type, &year, &price) == 5)
        {
            currentCar->year = year;
            currentCar->price = price;
            currentCar->nextCar = NULL;
            currentCar->carId = carId;

            // This section of the code ensures that the Car Id is unique as per the assignment specifications
            srand(time(NULL));
            while (lookForCarId(*headLL, currentCar->carId) != -1)
            {
                currentCar->carId += rand() % 999 + 1;
            }

            // Append the new car to the linked list
            if (*headLL == NULL)
            {
                *headLL = currentCar;
            }
            else
            {
                tail->nextCar = currentCar;
            }

            tail = currentCar;
        }
        else
        {
            printf("Error parsing line: %s\n", currentLine);
            free(currentCar);
        }
    }

    // Close the file after reading all the data
    fclose(file);
    printf("Data loaded successfully from %s\n", fileName);
}

