#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct queueStructure
{
    node *mainStackTop;
    node *secondaryStackTop;
} queueStructure;
node *createNode(int element)
{
    node *newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = element;
    return newNode;
}
int size(node *mainStackTop)
{
    int countOfElements = 0;
    while (mainStackTop)
    {
        countOfElements++;
        mainStackTop = mainStackTop->next;
    }
    return countOfElements;
}
void push(node **mainStackTop, int element)
{
    if (size(*mainStackTop) >= 100)
    {
        printf("Stack is full.");
        return;
    }
    node *newNode = createNode(element);
    newNode->next = *mainStackTop;
    *mainStackTop = newNode;
}
int pop(node **mainStackTop)
{
    if (*mainStackTop == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    int poppedValue = (*mainStackTop)->data;
    *mainStackTop = (*mainStackTop)->next;
    return poppedValue;
}
int peek(node *mainStackTop)
{
    if (mainStackTop == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }
    while (mainStackTop->next != NULL)
    {
        mainStackTop = mainStackTop->next;
    }
    return mainStackTop->data;
}
int isEmpty(node *mainStackTop)
{
    return (mainStackTop == NULL);
}
void enqueue(queueStructure*queue, int element)
{
    push(&queue->mainStackTop, element);
}
void swap(node **mainStackTop, node **secondaryStackTop){
    node *temporaryPointer=*mainStackTop;
    *mainStackTop=*secondaryStackTop;
    *secondaryStackTop=temporaryPointer;
}
int dequeue(queueStructure*queue)
{
    int sizeOfStack = size(queue->mainStackTop);
    while (sizeOfStack > 1)
    {
        int element = pop(&queue->mainStackTop);
        push(&queue->secondaryStackTop, element);
        sizeOfStack--;
    }
    int value = pop(&queue->mainStackTop);
    swap(&queue->mainStackTop, &queue->secondaryStackTop);
    return value;
}
void freeQueue(node *head){
    node *temporaryNode = head;
    while (head != NULL)
    {
        temporaryNode = head;
        head = head->next;
        free(temporaryNode);
        temporaryNode=NULL;
    }
}
int main()
{
    queueStructure*queue = (queueStructure*)malloc(sizeof(queueStructure));
    queue->mainStackTop = NULL;
    queue->secondaryStackTop = NULL;
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
            int peekElement = peek(queue->mainStackTop);
            if (peekElement != -1)
            {
                printf("Peek element: %d\n", peekElement);
            }
        }
        else if (choice == 4)
        {
            if (isEmpty(queue->mainStackTop))
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
            printf("Size: %d\n", size(queue->mainStackTop));
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
    freeQueue(queue->mainStackTop);
    return 0;
}
