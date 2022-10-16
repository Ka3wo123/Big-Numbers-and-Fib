#include "bignum.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int addBigNumbers(char a[], char b[], char result[])
{
    int lengthA = 0, lengthB = 0, numResult = 0, adder = 0, lengthResult = 0, numA, numB, lengthDiff;
    char tempResult[50], tempA[50] = {'\0'}, tempB[50] = {'\0'};

    strcpy(tempA, a);
    strcpy(tempB, b);


    for(int i = 0; a[i] != '\0'; i++)
    {
        if((((int) (a[i]) >= 48) && (int) (a[i]) <= 57))
        {
            lengthA++;
        } else
        {
            printf("Podano niepoprawna liczbe\n");
            return 1;
        }
    }

    for(int i = 0; b[i] != '\0'; i++)
    {
        if(((int) (b[i]) >= 48) && ((int) (b[i]) <= 57))
        {
            lengthB++;
        } else
        {
            printf("Podano niepoprawna liczbe\n");
            return 1;
        }
    }

    if(lengthA > lengthB)
    {
        lengthDiff = lengthA - lengthB;
        for(int i = 0; i < lengthDiff; i++)
        {
            strcat(tempB, "0");
            lengthB++;
        }

        for(int i = lengthB - 1; i >= lengthDiff; i--)
        {
            swap(&tempB[i], &tempB[i - lengthDiff]);
        }

    } else if(lengthA < lengthB)
    {
        lengthDiff = lengthB - lengthA;
        for(int i = 0; i < lengthDiff; i++)
        {
            strcat(tempA, "0");
            lengthA++;
        }

        for(int i = lengthB - 1; i >= lengthDiff; i--)
        {
            swap(&tempA[i], &tempA[i - lengthDiff]);
        }
    }

    for(int i = lengthA - 1; i >= 0; i--)
    {
        numA = ((int) (tempA[i] - '0'));
        numB = ((int) (tempB[i] - '0'));

        if(numA + numB + adder > 9)
        {
            numResult = numA + numB + adder - 10;
            itoa(numResult, tempResult, 10);
            strcat(result, tempResult);
            adder = 1;
        } else
        {
            numResult = numA + numB + adder;
            itoa(numResult, tempResult, 10);
            strcat(result, tempResult);
            adder = 0;
        }
    }

    if(adder == 1)
    {
        strcat(result, "1");
    }

    for(int i = 0; result[i] != '\0'; i++)
    {
        lengthResult++;
    }

    for(int i = 0; i < lengthResult / 2; i++)
    {
        swap(&result[i], &result[lengthResult - i - 1]);
    }

    return 0;
}

// swap char

void swap(char *a, char *b)
{    
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}










