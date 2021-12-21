#include<stdio.h>
#include"lenaArray.h"

void printArray(int size, int start, int end, int *lena);
void mirrored(int size, int start, int end, int *lena);
void calculateAverageGrayValue(int size, int start, int end, int *lena);
int calculateGrayValue(int start, int size, int end);
char asciiScale(char grayScale);

int main()
{
    const int size = 512; // int size
    const int subsetStart = 100; //int subsetStart
    const int subsetEnd = 400; // int subsetEnd

    printArray(size,0,size,*lena); // lena fucntion FUll size
    printArray(size,subsetStart,subsetEnd,*lena); // Lena small print size
    mirrored(size,subsetStart,subsetEnd,*lena); // Print lena function Mirrored version
    calculateAverageGrayValue(size, 0, size,*lena); // Print Average Vlaue Size Big
    calculateAverageGrayValue(size, subsetStart, subsetEnd,*lena); // Print Average Vlaue Size Small

    return 0;
}

void printArray(int size, int start, int end, int *lena)
{
    int grayValue, totalGrayValue;
    char asciiChar;
    /* PRINT-FACE*/
    for (int k = start; k < end; k++){  // Loop Top to Bottom
        for (int l = start; l < end; l++){  // loop Left to right
            grayValue = lena[calculateGrayValue(k, size, l)]; // Assign calue to function of calculateGrayValue
            asciiChar = asciiScale(grayValue);                // convert grayValue interger to ascii that equals asciichar
            printf("%c", asciiChar);                          // Print value with AsciiChar
        }
        printf("\n"); // Print new Line
    }
}

void mirrored(int size, int start, int end, int *lena)
{
    int grayValue, totalGrayValue;
    char asciiChar;
    /*Mirroed-FACE*/
    for(int i = start; i < end; i++)// Loop Top to Bottom
    {   for (int j = end; j > start; j--)// loop Right to Left
            {
                grayValue = lena[calculateGrayValue(i, size, j)]; // Assign calue to function of calculateGrayValue
                asciiChar = asciiScale(grayValue);                // convert grayValue interger to ascii that equals asciichar
                printf("%c", asciiChar);                          // Print value with AsciiChar
            }
            printf("\n"); // Print new Line
        }
    }

void calculateAverageGrayValue(int size, int start, int end, int *lena){
    int getaverageValue, totalValue;
    for (int i = start; i < end; i++) // Loop Top to Bottom
    {
        for (int j = start; j < end; j++) // loop Left to right
        {
            totalValue += lena[i * size + j]; // calculate Totalvalue
        }
    }
    getaverageValue = totalValue / (size * size);        // get Average value
    printf("AverageValueSmall: %d \n", getaverageValue); // print  Average Value for Small
}

int calculateGrayValue(int start, int size, int end){
    int value; 
    return value = start * size + end; // Return sum Value of Gray Value
}

char asciiScale(char grayScale) // char Store Characters, letters.Char type is Integer. 1 byte & stores value -128 to 127, 0 to 255
{
    if (25 > grayScale && grayScale < 50) // Both needs to e possitief for execute
        return '@';
    else if (50 > grayScale && grayScale < 75) //if grayScale groter dan 50 & kleiner dan 75 is
        return '%';
    else if (75 > grayScale && grayScale < 100)
        return '#';
    else if (100 > grayScale && grayScale < 125)
        return '*';
    else if (125 > grayScale && grayScale < 150)
        return '+';
    else if (150 > grayScale && grayScale < 175)
        return '=';
    else if (175 > grayScale && grayScale < 200)
        return '-';
    else if (200 > grayScale && grayScale < 225)
        return ':';
    else if (225 > grayScale && grayScale < 250)
        return '.';
    else
        return ' ';
}
