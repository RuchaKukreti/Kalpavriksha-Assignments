#include <stdio.h>
#include <stdlib.h>
#define maxSize 100
void enqueue(int *queue, int *front, int *rear, int element)
{
    if (*rear == maxSize - 1)
    {
        printf("Queue is full.\n");
        return;
    }
    if (*rear == -1)
    {
        *front = 0;
    }
    *rear = *rear + 1;
    queue[*rear] = element;
}
int dequeue(int *queue, int *front, int *rear)
{
    if (*front == -1 || *front > *rear)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    int element = queue[*front];
    *front = *front + 1;
    if (*front > *rear)
    {
        *front = -1;
        *rear = -1;
    }
    return element;
}
void peek(int *queue, int front, int rear)
{
    if (front == -1)
    {
        printf("Empty queue.\n");
        return;
    }
    printf("Peek element: %d\n", queue[front]);
}
void isEmpty(int *queue, int front, int rear)
{
    if (front == -1)
    {
        printf("True\n");
        return;
    }
    printf("False\n");
}
int size(int *queue, int front, int rear)
{
    if (front == -1)
    {
        return 0;
    }
    return (rear - front + 1);
}
int main()
{
    int queue[maxSize];
    int front = -1, rear = -1;
    int numberOfOperations = 0, choice = 0;
    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int operation = 0; operation < numberOfOperations; operation++)
    {
        printf("Press\n1.Enqueue\n2.Dequeue\n3.Peek\n4.isEmpty\n5.Size\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int element = 0;
            printf("Enter the element: ");
            scanf("%d", &element);
            enqueue(queue, &front, &rear, element);
        }
        else if (choice == 2)
        {
            int dequeuedElement = dequeue(queue, &front, &rear);
            if (dequeuedElement != -1)
            {
                printf("Dequeued element is: %d\n", dequeuedElement);
            }
        }
        else if (choice == 3)
        {
            peek(queue, front, rear);
        }
        else if (choice == 4)
        {
            isEmpty(queue, front, rear);
        }
        else if (choice == 5)
        {
            printf("Size: %d\n", size(queue, front, rear));
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