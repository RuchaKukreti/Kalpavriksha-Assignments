#include <stdio.h>
#include <stdlib.h>
int found_substring(char **array, int row, char *substring)
{
    int iterator = 0, column = 0, flag = 0;
    while (*(*(array + row) + (column)) != '\0')
    {
        if (*(*(array + row) + (column)) == substring[0])
        {
            while (*(substring + iterator) != '\0')
            {
                if (*(substring + iterator) == *(*(array + row) + (column)))
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
                iterator++;
                column++;
            }
        }
        column++;
    }
    if (flag)
    {
        printf("%s\n", *(array + row));
        return 1;
    }
    return 0;
}
int main()
{
    int totalstrings = 0;
    char substring[100] = {'\0'};
    printf("Enter number of strings:");
    scanf("%d", &totalstrings);
    char **array = malloc(totalstrings * sizeof(char *));
    printf("Enter strings.\n");
    for (int row = 0; row < totalstrings; row++)
    {
        *(array + row) = malloc(100 * sizeof(char));
        scanf("%s", *(array + row));
    }
    printf("Enter the substring: ");
    scanf("%s", substring);
    int count = 0;
    for (int row = 0; row < totalstrings; row++)
    {
        count += found_substring(array, row, substring);
    }
    printf("Number of occurences:%d", count);
    for (int row = 0; row < totalstrings; row++)
    {
        free(array[row]);
    }
    free(array);
    return 0;
}
