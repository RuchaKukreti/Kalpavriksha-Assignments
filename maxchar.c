#include <stdio.h>
#include <stdlib.h>
#define maxLength 50
int createArrayOfStrings(char **array, int numberOfStrings)
{
    for (int iterator = 0; iterator < numberOfStrings; iterator++)
    {
        *(array + iterator) = malloc(maxLength * sizeof(char));
        if (*(array + iterator) == NULL)
            return 1;
        printf("Enter string: ");
        scanf("%49s", *(array + iterator));
    }
    return 0;
}
void freeArray(char **array, int numberOfStrings)
{
    for (int iterator = 0; iterator < numberOfStrings; iterator++)
    {
        free(array[iterator]);
    }
}
int findMaxOccurence(char **array, int numberOfStrings, char characterToMatch, int *indexHavingMaxCharacter)
{
    int maxCount = -1;
    for (int row = 0; row < numberOfStrings; row++)
    {
        int count = 0, column = 0;
        while (*(*(array + row) + column) != '\0')
        {
            if (*(*(array + row) + column) == characterToMatch)
                count++;
            column++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            *indexHavingMaxCharacter = row;
        }
    }
    return maxCount;
}
int main()
{
    int numberOfStrings = 0;
    printf("Enter number of strings: ");
    scanf("%d", &numberOfStrings);
    if (numberOfStrings <= 0)
    {
        printf("Enter positive non-zero value of number of strings.\n");
        return 0;
    }
    char **array = malloc(numberOfStrings * sizeof(char *));
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    if (createArrayOfStrings(array, numberOfStrings))
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    char characterToMatch;
    int indexHavingMaxCharacter = 0;
    printf("Enter the character: ");
    scanf(" %c", &characterToMatch);
    int maxCountOfCharacter = findMaxOccurence(array, numberOfStrings, characterToMatch, &indexHavingMaxCharacter);
    printf("maxcount=%d\n", maxCountOfCharacter);
    printf("String having maximum occurence of character \'%c\' is: %s", characterToMatch, array[indexHavingMaxCharacter]);
    freeArray(array, numberOfStrings);
    free(array);
    array = NULL;
    return 0;
}