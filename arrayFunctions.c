#include "arrayFunctions.h"
#define GET_MINIMUM(currentMin, min) ((currentMin) > (min) ? (min) : (currentMin))
#define GET_MAXIMUM(currentMax, max) ((currentMax) < (max) ? (max) : (currentMax))

int minValue(int *array, unsigned int size)
{
    int minimum = array[0];
    array++;

    for(int i = 1; i < size; i++)
    {
        minimum = GET_MINIMUM(minimum, *array);
        array++;
    }

    return minimum;
}

int maxValue(int *array, unsigned int size)
{
    int maximum = array[0];
    array++;

    for(int i = 1; i < size; i++)
    {
        maximum = GET_MAXIMUM(maximum, *array);
        array++;
    }

    return maximum;
}


void fibbonaci(unsigned int n, int tab[])
{
    int *ptr = tab;
    int a = 1, b = 1;
    *ptr++ = 1;
    *ptr++ = 1;

    for(int i = 2; i < n; i++)
    {
        b += a;
        a = b - a;
        *ptr++ = b;
    }
}

void selectSort(int tab[], unsigned int size)
{
    int min, tmp;

    for(int i = 0; i < size - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < size; j++)
        {
            if(tab[j] < tab[min])
            {
                min = j;
            }
        }

        tmp = tab[min];
        tab[min] = tab[i];
        tab[i] = tmp;
    }
}

















