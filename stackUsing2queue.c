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
    queueStructure *queueTemporaray;
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
node *createNode(int element)
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
    node *newNode = createNode(element);
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
    node *temporaryNode = *front;
    int element = temporaryNode->data;
    *front = (*front)->next;
    if (*front == NULL)
    {
        *rear = NULL;
    }
    free(temporaryNode);
    temporaryNode=NULL;
    return element;
}
void peek(node *front)
{
    if (front == NULL)
    {
        printf("Empty.\n");
        return;
    }
    printf("Peek element: %d\n", front->data);
}
void isEmpty(node *front)
{
    if (front == NULL)
    {
        printf("True\n");
        return;
    }
    printf("False\n");
}
void push(queueStructure *queue, queueStructure *queueTemporaray, int value)
{
    enqueue(&queueTemporaray->front, &queueTemporaray->rear, value);
    int sizeOfQueue = size(queue->front);
    while (sizeOfQueue > 0)
    {
        int element = dequeue(&queue->front, &queue->rear);
        enqueue(&queueTemporaray->front, &queueTemporaray->rear, element);
        sizeOfQueue--;
    }
    sizeOfQueue = size(queueTemporaray->front);
    while (sizeOfQueue > 0)
    {
        int element = dequeue(&queueTemporaray->front, &queueTemporaray->rear);
        enqueue(&queue->front, &queue->rear, element);
        sizeOfQueue--;
    }
}
int pop(queueStructure *queue)
{
    return dequeue(&queue->front, &queue->rear);
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
void freeStack(stackStructure stack){
    freeQueue(stack.queue->front);
    freeQueue(stack.queueTemporaray->front);
}
int main()
{
    stackStructure stack;
    stack.queue = (queueStructure *)malloc(sizeof(queueStructure));
    stack.queue->front = NULL;
    stack.queue->rear = NULL;
    stack.queueTemporaray = (queueStructure *)malloc(sizeof(queueStructure));
    stack.queueTemporaray->front = NULL;
    stack.queueTemporaray->rear = NULL;
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
            push(stack.queue, stack.queueTemporaray, element);
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
            peek(stack.queue->front);
        }
        else if (choice == 4)
        {
            isEmpty(stack.queue->front);
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
    freeStack(stack);
    return 0;
}
