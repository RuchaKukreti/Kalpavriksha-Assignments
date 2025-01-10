#include <stdio.h>
#include <stdlib.h>
int trace(int **matrix, int rows)
{
    int sum = 0;
    for (int row = 0; row < rows; row++)
    {
        sum += matrix[row][row];
    }
    return sum;
}
void free_matrix(int **matrix, int rows)
{
    for (int row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}
int main()
{
    int rows = 0;
    printf("Enter the order of matrix: ");
    scanf("%d", &rows);
    if (rows < 1)
    {
        printf("Enter positive non-zero value.");
        return 0;
    }
    int **matrix1 = malloc(rows * sizeof(int *));
    int **matrix2 = malloc(rows * sizeof(int *));
    printf("Enter matrix 1 elements\n");
    for (int row = 0; row < rows; row++)
    {
        matrix1[row] = malloc(rows * sizeof(int));
        for (int column = 0; column < rows; column++)
        {
            scanf("%d", &matrix1[row][column]);
        }
    }
    printf("Enter matrix 2 elements\n");
    for (int row = 0; row < rows; row++)
    {
        matrix2[row] = malloc(rows * sizeof(int));
        for (int column = 0; column < rows; column++)
        {
            scanf("%d", &matrix2[row][column]);
        }
    }
    int trace1 = trace(matrix1, rows);
    int trace2 = trace(matrix2, rows);
    if (trace1 == trace2)
    {
        printf("Both matrices have equal traces.");
    }
    else
    {
        printf("Both matrices do not have equal traces.");
    }
    free_matrix(matrix1, rows);
    free_matrix(matrix2, rows);
    return 0;
}