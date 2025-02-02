#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int size(node *front)
{
    int countOfElements = 0;
    while (front != NULL)
    {
        countOfElements++;
        front = front->next;
    }
    return countOfElements;
}
node *create(int element)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = element;
    return newNode;
}
void enqueue(node **front, node **rear, int element)
{
    node *newNode = create(element);
    if (*rear == NULL)
    {
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}
int dequeue(node **front, node **rear)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    node *temp = *front;
    int element = temp->data;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    free(temp);
    return element;
}
void peek(node *front, node *rear)
{
    if (front == NULL)
    {
        printf("Empty queue.\n");
        return;
    }
    printf("Peek element: %d\n", front->data);
}
void isEmpty(node *front, node *rear)
{
    if (front == NULL)
    {
        printf("True\n");
        return;
    }
    printf("False\n");
}
int main()
{
    node *front = NULL, *rear = NULL;
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
            enqueue(&front, &rear, element);
        }
        else if (choice == 2)
        {
            int dequeuedElement = dequeue(&front, &rear);
            if (dequeuedElement != -1)
            {
                printf("Dequeued element is: %d\n", dequeuedElement);
            }
        }
        else if (choice == 3)
        {
            peek(front, rear);
        }
        else if (choice == 4)
        {
            isEmpty(front, rear);
        }
        else if (choice == 5)
        {
            printf("Size: %d\n", size(front));
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