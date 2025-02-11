#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
typedef struct queueStructure
{
    node *stackTop;
} queueStructure;
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
    node *temporaryNode=*stackTop;
    int poppedValue = (*stackTop)->data;
    *stackTop = (*stackTop)->next;
    free(temporaryNode);
    temporaryNode=NULL;
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
void enqueue(queueStructure *queue, int element)
{
    push(&queue->stackTop, element);
}
int dequeue(queueStructure *queue)
{
    if(queue->stackTop == NULL){
        return -1;
    }
    int poppedValue = pop(&queue->stackTop);
    if(queue->stackTop != NULL){
        int dequeuedValue = dequeue(queue);
        enqueue(queue, poppedValue);
        return dequeuedValue;
    }
    return poppedValue;
}
void freeStack(node *top){
    while(top!=NULL){
        pop(&top);
    }
}
int main()
{
    queueStructure *queue = (queueStructure *)malloc(sizeof(queueStructure));
    queue->stackTop = NULL;
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
            else
            {
                printf("Empty queue.\n");
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
    freeStack(queue->stackTop);
    queue->stackTop=NULL;
    return 0;
}
