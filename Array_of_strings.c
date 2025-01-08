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
    printf("Enter number of rows:");
    scanf("%d", &rows);
    printf("Enter number of columns:");
    scanf("%d", &columns);
    if (rows < 1 || rows > 10 || columns < 1 || columns > 101)
    {
        printf("Enter value of rows between 1 and 10 & Enter value of columns between 1 and 101.\n");
        return 0;
    }
    char ***array = malloc(rows * sizeof(char **));
    printf("Enter the names:\n");
    for (int row = 0; row < rows; row++)
    {
        array[row] = malloc(columns * sizeof(char *));
        for (int column = 0; column < columns; column++)
        {
            array[row][column] = malloc(50 * sizeof(char));
            printf("Name at (%d,%d):",row,column);
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
    printf("\n");
    printf("Number of names starting with a vowel:%d\n", vowels);
    printf("The longest name:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {   
            if(strlen(array[row][column]) == max_length){
            
                printf("%s\n", array[row][column]);
            
            }
        }
    }
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            free(array[row][column]);
        }
        free(array[row]);
    }
    free(array);
    return 0;
}
