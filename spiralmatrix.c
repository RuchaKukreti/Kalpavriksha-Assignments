#include <stdio.h>
#include <stdlib.h>
int main()
{
    int rows, columns;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);
    if (rows == 0 || columns == 0)
    {
        printf("Enter non zero number for number of rows and columns");
        return 0;
    }
    int top = 0, bottom = rows - 1, left = 0, right = columns - 1;
    int **array = malloc(rows * sizeof(int *));
    for (int row = 0; row < rows; row++)
    {
        array[row] = malloc(columns * sizeof(int));
        for (int column = 0; column < columns; column++)
        {
            scanf("%d", &array[row][column]);
        }
    }
    printf("Matrix:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%d  ", array[row][column]);
        }
        printf("\n");
    }
    printf("Spiral Traversal:\n");
    while (left <= right && top <= bottom)
    {
        for (int row = left; row <= right; row++)
        {
            printf("%d ", array[top][row]);
        }
        top++;
        for (int row = top; row <= bottom; row++)
        {
            printf("%d ", array[row][right]);
        }
        right--;
        if (top > bottom || left > right)
            break;
        for (int row = right; row >= left; row--)
        {
            printf("%d ", array[bottom][row]);
        }
        bottom--;
        for (int row = bottom; row >= top; row--)
        {
            printf("%d ", array[row][left]);
        }
        left++;
    }
    for (int row = 0; row < rows; row++)
    {
        free(array[row]);
    }
    free(array);
    return 0;
}
