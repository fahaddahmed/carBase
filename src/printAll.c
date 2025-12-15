#include "header.h"
#include <stdio.h>

/**
 * @brief Prints all cars in the linked list
 * @param headLL The head of the linked list
 */
void printAll(struct car *headLL)
{
    int counter = 0;

    if (headLL == NULL)
    {
        printf("No cars found.\n");
        return;
    }

    while (headLL != NULL)
    {
        // Indicates which car index is being printed
        counter++;
        printf("Car # %d:\n", counter);

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
        printf("\tYear of Manufacture: %d\n\n", headLL->year);

        headLL = headLL->nextCar;
    }

    printf("Currently, there are %d cars.\n", counter);
}

