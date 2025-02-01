#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
void push(int *stack, int *top, int element)
{
    if (*top >= 100)
    {
        printf("Stack is full.");
        return;
    }
    *top = *top + 1;
    stack[*top] = element;
}
int pop(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int poppedValue = stack[*top];
    *top = *top - 1;
    return poppedValue;
}
int peek(int *stack, int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[*top];
}
int isEmpty(int *stack, int top)
{
    return (top == -1);
}
int main()
{
    int top = -1;
    int stack[maxSize];
    int numberOfOperations = 0, choice = 0;
    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int operation = 0; operation < numberOfOperations; operation++)
    {
        printf("Press\n1.push\n2.pop\n3.peek\n4.isEmpty\n5.size\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter element to be pushed: ");
            int element = 0;
            scanf("%d", &element);
            push(stack, &top, element);
        }
        else if (choice == 2)
        {
            int poppedValue = pop(stack, &top);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
        }
        else if (choice == 3)
        {
            int peekElement = peek(stack, &top);
            if (peekElement != -1)
            {
                printf("Peek element: %d\n", peekElement);
            }
        }
        else if (choice == 4)
        {
            if (isEmpty(stack, top))
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
        else if (choice == 5)
        {
            printf("Size: %d\n", top + 1);
        }
        else if (choice == 6)
        {
            printf("Exiting.\n");
            break;
        }
        else
        {
            printf("Enter valid choice.\n");
        }
    }
    return 0;
}