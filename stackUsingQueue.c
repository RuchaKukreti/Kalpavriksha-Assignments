#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct queueStructure
{
    node *front;
    node *rear;
} queueStructure;
typedef struct stackStructure
{
    queueStructure *queue;
} stackStructure;
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
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return newNode;
    }
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
        printf("Empty.\n");
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
        printf("Empty.\n");
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
void push(queueStructure *queue, int value)
{
    enqueue(&queue->front, &queue->rear, value);
    int sizeOfQueue = size(queue->front);
    while (sizeOfQueue > 1)
    {
        int element = dequeue(&queue->front, &queue->rear);
        enqueue(&queue->front, &queue->rear, element);
        sizeOfQueue--;
    }
}
int pop(queueStructure *queue)
{
    return dequeue(&queue->front, &queue->rear);
}
int main()
{
    stackStructure stack;
    stack.queue = (queueStructure *)malloc(sizeof(queueStructure));
    stack.queue->front = NULL;
    stack.queue->rear = NULL;
    int numberOfOperations = 0, choice = 0;
    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int operation = 0; operation < numberOfOperations; operation++)
    {
        printf("Press\n1.Push\n2.Pop\n3.Peek\n4.isEmpty\n5.Size\n6.Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int element = 0;
            printf("Enter the element: ");
            scanf("%d", &element);
            push(stack.queue, element);
        }
        else if (choice == 2)
        {
            int poppedElement = pop(stack.queue);
            if (poppedElement != -1)
            {
                printf("Popped element is: %d\n", poppedElement);
            }
        }
        else if (choice == 3)
        {
            peek(stack.queue->front, stack.queue->rear);
        }
        else if (choice == 4)
        {
            isEmpty(stack.queue->front, stack.queue->rear);
        }
        else if (choice == 5)
        {
            printf("Size: %d\n", size(stack.queue->front));
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