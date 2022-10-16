#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arrayFunctions.h"
#include "bignum.h"
#define NULL 0
#define NUM_SIZE 50

int main()
{
    srand(time(NULL));

    int *integerDigits, minimum, maximum, digitInArray, *fibValues, valuesCounter = 0, x;
    unsigned int arraySize;
    char number1[NUM_SIZE], number2[NUM_SIZE], result[NUM_SIZE + 2] = {'\0'}, flag;

    arraySize = rand() % 20 + 1;

    integerDigits = malloc(arraySize * sizeof(*integerDigits));

    if(integerDigits == NULL)
    {
        printf("Nie udalo sie przydzielic pamieci\n");
        return 1;
    }

    fibValues = malloc(arraySize * sizeof(*fibValues));

    if(fibValues == NULL)
    {
        printf("Nie udalo sie przydzielic pamieci\n");
        return 1;
    }

    for(int i = 0; i < arraySize; i++)
    {
        digitInArray = rand() % 700 + 1;
        integerDigits[i] = digitInArray;
    }

    printf("Nieposortowana tablica (%d): ", arraySize);

    for(int i = 0; i < arraySize; i++)
    {
        printf("%d ", integerDigits[i]);
    }

    putchar('\n');

    minimum = minValue(integerDigits, arraySize);
    maximum = maxValue(integerDigits, arraySize);


    printf("Najmniejsza wartosc w tablicy: %d\nNajwieksza wartosc w tablicy: %d\n", minimum, maximum);

    putchar('\n');

    fibbonaci(arraySize, fibValues);

    printf("Ciag Fibbonaciego: ");

    for(int i = 0; i < arraySize; i++)
    {
        printf("%d ", fibValues[i]);
    }

    putchar('\n');

    while(*fibValues <= maximum)
    {
        if(*fibValues >= minimum)
        {
            valuesCounter++;
            fibValues++;
        } else
        {
            fibValues++;
        }
    }

    printf("Ilosc liczb Fibbonaciego w przedziale <%d, %d> = %d\n", minimum, maximum, valuesCounter);

    selectSort(integerDigits, arraySize);

    putchar('\n');
    printf("Posortowana tablica (%d): ", arraySize);

    for(int i = 0; i < arraySize; i++)
    {
        printf("%d ", integerDigits[i]);
    }

    free(integerDigits);
    integerDigits = NULL;

    putchar('\n');
    putchar('\n');

    printf("Czy chcesz dodac duze liczby?\nT / N\n");
    scanf("%c", &flag);

    if(flag == 'T' || flag == 't')
    {
        printf("Podaj dwie, dodatnie liczby calkowite:\n");
        scanf("%s %s", number1, number2);

        x = addBigNumbers(number1, number2, result);

        while(x != 0)
        {
            printf("Podaj dwie, dodatnie liczby calkowite:\n");
            scanf("%s %s", number1, number2);

            x = addBigNumbers(number1, number2, result);
        }

        printf("%s + %s = %s\n", number1, number2, result);

        FILE *fp = fopen("..\\projekt2\\wyniki.txt", "a");

        if(fp == NULL)
        {
            printf("Nie udalo sie otworzyc pliku\n");
            return 1;
        }

        fprintf(fp, "Wynik dodawania: %s + %s = %s\n", number1, number2, result);
        fclose(fp);
        fp = NULL;
    }

}



