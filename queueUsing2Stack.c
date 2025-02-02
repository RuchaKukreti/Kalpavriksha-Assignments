#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct que
{
    node *stackTop;
    node *stackTemp;
} que;
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
    while (stackTop->next != NULL)
    {
        stackTop = stackTop->next;
    }
    return stackTop->data;
}
int isEmpty(node *stackTop)
{
    return (stackTop == NULL);
}
void enqueue(que *queue, int element)
{
    push(&queue->stackTop, element);
}
int dequeue(que *queue)
{
    int sizeOfStack = size(queue->stackTop);
    while (sizeOfStack > 1)
    {
        int element = pop(&queue->stackTop);
        push(&queue->stackTemp, element);
        sizeOfStack--;
    }
    int value = pop(&queue->stackTop);
    sizeOfStack = size(queue->stackTemp);
    while (sizeOfStack > 1)
    {
        int element = pop(&queue->stackTemp);
        push(&queue->stackTop, element);
        sizeOfStack--;
    }
    return value;
}

int main()
{
    que *queue = (que *)malloc(sizeof(que));
    queue->stackTop = NULL;
    queue->stackTemp = NULL;
    int numberOfOperations = 0, choice = 0;
    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int operation = 0; operation < numberOfOperations; operation++)
    {
        printf("Press\n1.Enqueue\n2.Dequeue\n3.peek\n4.isEmpty\n5.size\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter element to be enqueued: ");
            int element = 0;
            scanf("%d", &element);
            enqueue(queue, element);
        }
        else if (choice == 2)
        {
            int dequeuedValue = dequeue(queue);
            if (dequeuedValue != -1)
            {
                printf("Dequeued value: %d\n", dequeuedValue);
            }
        }
        else if (choice == 3)
        {
            int peekElement = peek(queue->stackTop);
            if (peekElement != -1)
            {
                printf("Peek element: %d\n", peekElement);
            }
        }
        else if (choice == 4)
        {
            if (isEmpty(queue->stackTop))
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
            printf("Size: %d\n", size(queue->stackTop));
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
