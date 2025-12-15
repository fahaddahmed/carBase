#include "header.h"
#include <stdio.h>

/**
 * @brief Prints the details of a car at a specific position in the linked list
 * @param headLL The head of the linked list
 * @param whichOne The position of the car to print
 */
void printOne(struct car *headLL, int whichOne)
{
    int currIndex = 1;

    while (headLL != NULL && currIndex < whichOne)
    {
        headLL = headLL->nextCar;
        currIndex++;
    }

    if (headLL != NULL && currIndex == whichOne)
    {
        printf("\tCar id: %d\n", headLL->carId);
        printf("\tModel: %s\n", headLL->model);
        printf("\tType: %s\n", headLL->type);

        // Print price in the format CDN $X,XXX.YY
        int price_int = (int)headLL->price;
        int price_frac = (int)((headLL->price - price_int) * 100);
        if (price_int >= 1000)
        {
            printf("\tPrice: CDN $%d,%03d.%02d\n", price_int / 1000, price_int % 1000, price_frac);
        }
        else
        {
            printf("\tPrice: CDN $%d.%02d\n", price_int, price_frac);
        }
        printf("\tYear of Manufacture: %d\n", headLL->year);
    }
    else
    {
        printf("Position %d does not exist in the list.\n", whichOne);
    }
}

