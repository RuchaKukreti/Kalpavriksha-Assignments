/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return 1;
    }
    return 0;
}
int main()
{
    int rows, columns, vowels = 0, max_length = 0;
    char longest_name[100] = {'\0'};
    scanf("%d%d", &rows, &columns);
    if (rows == 0 || columns == 0)
    {
        printf("Enter non-zero values of rows and columns.");
        return 0;
    }
    char ***array = malloc(rows * sizeof(char **));
    for (int row = 0; row < rows; row++)
    {
        array[row] = malloc(columns * sizeof(char *));
        for (int column = 0; column < columns; column++)
        {
            array[row][column] = malloc(50 * sizeof(char));
            scanf("%s", array[row][column]);
            if (strlen(array[row][column]) > max_length)
            {
                max_length = strlen(array[row][column]);
                strcpy(longest_name, array[row][column]);
            }
            if (is_vowel(array[row][column][0]))
            {
                vowels++;
            }
        }
    }
    printf("The 2D array of names is:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%s ", array[row][column]);
        }
        printf("\n");
    }
    printf("Number of names starting with a vowel:%d\n", vowels);
    printf("The longest name:%s", longest_name);
    return 0;
}