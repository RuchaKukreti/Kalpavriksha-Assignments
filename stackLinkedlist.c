#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
typedef struct node
{
    int data;
    struct node *next;
} node;
node *createNode(int element)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = element;
    return newNode;
}
int size(node *stackTop)
{
    int countOfElements = 0;
    while (stackTop)
    {
        countOfElements++;
        stackTop = stackTop->next;
    }
    return countOfElements;
}
void push(node **stackTop, int element)
{
    if (size(*stackTop) >= 100)
    {
        printf("Stack is full.");
        return;
    }
    node *newNode = createNode(element);
    newNode->next = *stackTop;
    *stackTop = newNode;
}
int pop(node **stackTop)
{
    if (*stackTop == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int poppedValue = (*stackTop)->data;
    *stackTop = (*stackTop)->next;
    return poppedValue;
}
int peek(node *stackTop)
{
    if (stackTop == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stackTop->data;
}
int isEmpty(node *stackTop)
{
    return (stackTop == NULL);
}
int main()
{
    node *stackTop = NULL;
    int numberOfOperations = 0, choice = 0;
    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int i = 0; i < numberOfOperations; i++)
    {
        printf("Press\n1.push\n2.pop\n3.peek\n4.isEmpty\n5.size\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter element to be pushed: ");
            int element = 0;
            scanf("%d", &element);
            push(&stackTop, element);
        }
        else if (choice == 2)
        {
            int poppedValue = pop(&stackTop);
            if (poppedValue != -1)
            {
                printf("Popped value: %d\n", poppedValue);
            }
        }
        else if (choice == 3)
        {
            int peekElement = peek(stackTop);
            if (peekElement != -1)
            {
                printf("Peek element: %d\n", peekElement);
            }
        }
        else if (choice == 4)
        {
            if (isEmpty(stackTop))
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
            printf("Size: %d\n", size(stackTop));
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