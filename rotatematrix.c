#include <stdio.h>
#include<stdlib.h>
void swap(int *value1,int *value2){
    int temporary=*value1;
    *value1=*value2;
    *value2=temporary;
}
int main()
{   int rows;
    printf("Enter order of matrix: ");
    scanf("%d",&rows);
    if(rows==0){
        printf("Enter non zero number for order of matrix.");
        return 0;
    }
    int top=0,bottom=rows-1,left=0,right=rows-1;
    int **array=malloc(rows*sizeof(int*));
    for(int row=0;row<rows;row++){
        array[row]=malloc(rows*sizeof(int));
        for(int column=0;column<rows;column++){
            scanf("%d",&array[row][column]);
        }
    }
    for(int row=0;row<rows;row++){
        for(int column=0;column<row;column++){
            swap(&array[row][column],&array[column][row]);
        }
    }
    int mid=rows/2;
    for(int row=0;row<rows;row++){
        for(int column=0;column<rows;column++){
            if(column>mid-1)break;
            swap(&array[row][column],&array[row][rows-column-1]);
        }
    }
    for(int row=0;row<rows;row++){
        for(int column=0;column<rows;column++){
            printf("%d  ",array[row][column]);
        }
        printf("\n");
    }
    for(int row=0;row<rows;row++){
            free(array[row]);
    }
    free(array);
    return 0;
    }
 