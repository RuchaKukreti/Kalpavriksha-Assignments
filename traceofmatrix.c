#include <stdio.h>
#include <stdlib.h>
int inputMatrix(int **matrix, int size)
{
    printf("Enter matrix elements.\n");
    for (int row = 0; row < size; row++)
    {
        matrix[row] = malloc(size * sizeof(int));
        if (matrix[row] == NULL)
        {
            return 1;
        }
        for (int column = 0; column < size; column++)
        {
            scanf("%d", &matrix[row][column]);
        }
    }
    return 0;
}
int trace(int **matrix, int size)
{
    int sum = 0;
    for (int diagonal = 0; diagonal < size; diagonal++)
    {
        sum += matrix[diagonal][diagonal];
    }
    return sum;
}
void checkIfTracesAreEqual(int trace1, int trace2)
{
    if (trace1 == trace2)
    {
        printf("Both matrices have equal traces.");
    }
    else
    {
        printf("Both matrices do not have equal traces.");
    }
}
void freeMatrix(int **matrix, int size)
{
    for (int row = 0; row < size; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}
int main()
{
    int size = 0;
    printf("Enter the order of matrix: ");
    scanf("%d", &size);
    if (size < 1)
    {
        printf("Enter positive non-zero value.");
        return 0;
    }
    int **matrix1 = malloc(size * sizeof(int *));

    int **matrix2 = malloc(size * sizeof(int *));
    if (matrix1 == NULL || matrix2 == NULL)
    {
        printf("Memory allocation failed.");
        return 0;
    }
    if (inputMatrix(matrix1, size) || inputMatrix(matrix2, size))
    {
        printf("Memory allocation failed.");
        return 0;
    }
    int trace1 = trace(matrix1, size);
    int trace2 = trace(matrix2, size);
    checkIfTracesAreEqual(trace1, trace2);
    freeMatrix(matrix1, size);
    matrix1 = NULL;
    freeMatrix(matrix2, size);
    matrix2 = NULL;
    return 0;
}