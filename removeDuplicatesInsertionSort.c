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
void createList(node **head, int value)
{
    if (*head == NULL)
    {
        *head = createNode(value);
        return;
    }
    node *pointerToHead = *head;
    while (pointerToHead->next != NULL)
    {
        pointerToHead = pointerToHead->next;
    }
    pointerToHead->next = createNode(value);
}
void inputElements(node **head, int numberOfElements)
{
    int element = 0;
    for (int iterator = 1; iterator < numberOfElements + 1; iterator++)
    {
        printf("Enter element %d :", iterator);
        scanf("%d", &element);
        createList(head, element);
    }
}
void printElements(node *head)
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    printf("[ ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}
node *sortedInsert(node *current, node *sortedHead)
{
    if (sortedHead == NULL || sortedHead->data >= current->data)
    {
        current->next = sortedHead;
        sortedHead = current;
    }
    else
    {
        node *head = sortedHead;
        while (head->next != NULL && head->next->data < current->data)
        {
            head = head->next;
        }
        current->next = head->next;
        head->next = current;
    }
    return sortedHead;
}
node *insertionSortList(node *head)
{
    node *sortedHead = NULL, *current = head;
    while (current != NULL)
    {
        node *nextNode = current->next;
        sortedHead = sortedInsert(current, sortedHead);
        current = nextNode;
    }
    return sortedHead;
}
node *distinctList(node *head)
{
    node *temp = head, *prev = head;
    while (temp != NULL && temp->next != NULL)
    {
        prev = temp;
        while (temp != NULL && prev->data == temp->data)
        {
            temp = temp->next;
        }
        prev->next = temp;
    }
    return head;
}
void freeLinkedList(node *head)
{

    node *temp = head;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
    }
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
    printf("Distinct sorted List:\n");
    node *newHead = insertionSortList(head);
    newHead = distinctList(newHead);
    printElements(newHead);
    freeLinkedList(head);
    return 0;
}