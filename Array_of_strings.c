#include <stdio.h>
#include <stdlib.h>
#define maxRows 10
#define maxColumns 101
#define maxNameSize 50
int isVowel(char character)
{
    return (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' ||
            character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U');
}
int stringLength(char *string)
{
    int count = 0;
    while (string[count] != '\0')
    {
        count++;
    }
    return count;
}
void inputArray(char ***array, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("Name at (%d,%d):", row, column);
            scanf("%49s", array[row][column]);
        }
    }
}
int countNamesStartingWithVowels(char ***array, int rows, int columns)
{
    int vowelNames = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (isVowel(array[row][column][0]))
            {
                vowelNames++;
            }
        }
    }
    return vowelNames;
}
int allocateArray(char ***array, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        array[row] = malloc(columns * sizeof(char *));
        if (array[row] == NULL)
        {
            return 1;
        }
        for (int column = 0; column < columns; column++)
        {
            array[row][column] = malloc(maxNameSize * sizeof(char));
            if (array[row][column] == NULL)
            {
                return 1;
            }
        }
    }
    inputArray(array, rows, columns);
    return 0;
}
void printArray(char ***array, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%s ", array[row][column]);
        }
        printf("\n");
    }
}
void printLongestNames(char ***array, int rows, int columns, int maxLength)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (stringLength(array[row][column]) == maxLength)
            {

                printf("%s\n", array[row][column]);
            }
        }
    }
}
void freeArray(char ***array, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            free(array[row][column]);
        }
        free(array[row]);
    }
    free(array);
    array = NULL;
}
int calculateMaxLength(char ***array, int rows, int columns)
{
    int maxLength = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (stringLength(array[row][column]) > maxLength)
            {
                maxLength = stringLength(array[row][column]);
            }
        }
    }
    return maxLength;
}
int main()
{
    int rows, columns, vowels = 0, maxLength = 0;
    printf("Enter number of rows:");
    scanf("%d", &rows);
    printf("Enter number of columns:");
    scanf("%d", &columns);
    if (rows < 1 || rows > maxRows || columns < 1 || columns > maxColumns)
    {
        printf("Enter value of rows between 1 and 10 & Enter value of columns between 1 and 101.\n");
        return 0;
    }
    char ***array = malloc(rows * sizeof(char **));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    printf("Enter the names:\n");
    if (allocateArray(array, rows, columns))
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    printf("The 2D array of names is:\n");
    printArray(array, rows, columns);
    printf("\n");
    printf("Number of names starting with a vowel:%d\n", countNamesStartingWithVowels(array, rows, columns));
    printf("The longest name:\n");
    maxLength = calculateMaxLength(array, rows, columns);
    printLongestNames(array, rows, columns, maxLength);
    freeArray(array, rows, columns);
    return 0;
}