#include <stdio.h>
#include <stdlib.h>
int foundSubstring(char **array, int row, char *substring)
{
    int iterator = 0, column = 0, flag = 0;
    while (*(*(array + row) + (column)) != '\0')
    {
        if (*(*(array + row) + (column)) == substring[0])
        {
            iterator = 0;
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
int inputStrings(char **array, int totalstrings)
{
    for (int iterator = 0; iterator < totalstrings; iterator++)
    {
        *(array + iterator) = malloc(100 * sizeof(char));
        if (*(array + iterator) == NULL)
            return 1;
        printf("Enter string: ");
        scanf("%s", *(array + iterator));
    }
    return 0;
}
int calculateNumberOfOccurence(char **array, int totalstrings, char *substring)
{
    int numberOfOccurence = 0;
    for (int iterator = 0; iterator < totalstrings; iterator++)
    {
        numberOfOccurence += foundSubstring(array, iterator, substring);
    }
    return numberOfOccurence;
}
void freeArray(char **array, int totalstrings)
{
    for (int iterator = 0; iterator < totalstrings; iterator++)
    {
        free(array[iterator]);
    }
    free(array);
}
int main()
{
    int totalstrings = 0;
    char substring[100] = {'\0'};
    printf("Enter number of strings:");
    scanf("%d", &totalstrings);
    if (totalstrings <= 0)
    {
        printf("Enter positive and non-zero value for number of strings.");
        return 0;
    }
    char **array = malloc(totalstrings * sizeof(char *));
    if (array == NULL || inputStrings(array, totalstrings))
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    printf("Enter the substring: ");
    scanf("%s", substring);
    printf("The substring is found in the following strings:\n");
    int numberOfOccurence = calculateNumberOfOccurence(array, totalstrings, substring);
    printf("Number of occurences:%d", numberOfOccurence);
    freeArray(array, totalstrings);
    array = NULL;
    return 0;
}