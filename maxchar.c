#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void copy_string(char *string1, char *string2)
{
    int itr = 0;
    while (string2[itr] != '\0')
    {
        string1[itr] = string2[itr];
        itr++;
    }
}
int main()
{
    int rows = 0;
    printf("Enter number of strings: ");
    scanf("%d", &rows);
    char **array = malloc(sizeof(char *));
    for (int row = 0; row < rows; row++)
    {
        *(array + row) = malloc(50 * sizeof(char));
        scanf("%s", *(array + row));
    }
    char character;
    int maxcount = 0;
    char string[50];
    printf("Enter the character: ");
    scanf(" %c", &character);
    for (int row = 0; row < rows; row++)
    {
        int count = 0, itr = 0;
        while (*(*(array + row) + itr) != '\0')
        {
            if (*(*(array + row) + itr) == character)
                count++;
            itr++;
        }
        if (count > maxcount)
        {
            maxcount = count;
            copy_string(string, *(array + row));
        }
    }
    printf("maxcount=%d\n", maxcount);
    printf("%s", string);
    for (int row = 0; row < rows; row++)
    {
        free(array[row]);
    }
    free(array);
    return 0;
}
