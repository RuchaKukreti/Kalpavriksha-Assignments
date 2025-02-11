#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *createNode(int value)
{
    node *temporaryNode = malloc(sizeof(node));
    if (temporaryNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return temporaryNode;
    }
    temporaryNode->data = value;
    temporaryNode->next = NULL;
    return temporaryNode;
}
void addNodeToList(node **head, int value)
{
    if (*head == NULL)
    {
        *head = createNode(value);
        return;
    }
    node *traversalPointer = *head;
    while (traversalPointer->next != NULL)
    {
        traversalPointer = traversalPointer->next;
    }
    traversalPointer->next = createNode(value);
}
void inputElements(node **head, int numberOfElements)
{
    int element = 0;
    for (int iterator = 1; iterator < numberOfElements + 1; iterator++)
    {
        printf("Enter element %d :", iterator);
        scanf("%d", &element);
        addNodeToList(head, element);
    }
}
void printElements(node *head)
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    while (head != NULL)
    {
        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeLinkedList(node *head)
{
    node *temporaryNode = head;
    while (head != NULL)
    {
        temporaryNode = head;
        head = head->next;
        free(temporaryNode);
        temporaryNode=NULL;
    }
}

void removeMiddleNode(node **head)
{
    if ((*head)->next == NULL)
    {
        *head = NULL;
        return;
    }
    node *fastPointer = *head, *slowPointer = *head, *previousPointer = *head;
    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        previousPointer = slowPointer;
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
    }
    previousPointer->next = slowPointer->next;
}
int main()
{
    int numberOfElements = 0;
    node *head = NULL;
    printf("Enter the number of elements of linkedlist: ");
    scanf("%d", &numberOfElements);
    inputElements(&head, numberOfElements);
    printf("List:\n");
    printElements(head);
    removeMiddleNode(&head);
    printf("List after removing the middle node.\n");
    printElements(head);
    freeLinkedList(head);
    return 0;
}
