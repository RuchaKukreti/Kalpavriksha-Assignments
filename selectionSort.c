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
    while (head != NULL)
    {
        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
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
node *sortList(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *sorted = NULL;
    while (head != NULL)
    {
        node *minimumNode = head, *previousMinimum = NULL, *current = head, *previousNode = NULL;
        while (current != NULL)
        {
            if (current->data < minimumNode->data)
            {
                minimumNode = current;
                previousMinimum = previousNode;
            }
            previousNode = current;
            current = current->next;
        }
        if (minimumNode == head)
        {
            head = head->next;
        }
        else
        {
            previousMinimum->next = minimumNode->next;
        }
        minimumNode->next = sorted;
        sorted = minimumNode;
    }
    node *previousNode = NULL;
    node *current = sorted;
    while (current != NULL)
    {
        node *next = current->next;
        current->next = previousNode;
        previousNode = current;
        current = next;
    }
    return previousNode;
}
node *mergeTwoSortedLists(node **head1, node **head2)
{
    node *pointerToHead1 = *head1, *pointerToHead2 = *head2, *head = NULL;
    if (!pointerToHead1)
        return pointerToHead2;
    if (!pointerToHead2)
        return pointerToHead1;
    if (pointerToHead1->data < pointerToHead2->data)
    {
        head = pointerToHead1;
        pointerToHead1 = pointerToHead1->next;
    }
    else
    {
        head = pointerToHead2;
        pointerToHead2 = pointerToHead2->next;
    }
    node *pointerToHead = head;
    while (pointerToHead1 != NULL && pointerToHead2 != NULL)
    {
        if (pointerToHead1->data < pointerToHead2->data)
        {
            pointerToHead->next = pointerToHead1;
            pointerToHead = pointerToHead->next;
            pointerToHead1 = pointerToHead1->next;
        }
        else
        {
            pointerToHead->next = pointerToHead2;
            pointerToHead = pointerToHead->next;
            pointerToHead2 = pointerToHead2->next;
        }
    }
    if (pointerToHead1)
    {
        pointerToHead->next = pointerToHead1;
    }
    else if (pointerToHead2)
    {
        pointerToHead->next = pointerToHead2;
    }
    return head;
}
int main()
{
    int numberOfElements = 0;
    node *head1 = NULL, *head2 = NULL;
    printf("Enter the number of elements of linkedlist 1: ");
    scanf("%d", &numberOfElements);
    inputElements(&head1, numberOfElements);
    printf("Enter the number of elements of linkedlist 2: ");
    scanf("%d", &numberOfElements);
    inputElements(&head2, numberOfElements);
    printf("List 1:\n");
    printElements(head1);
    printf("List 2:\n");
    printElements(head2);
    node *temporaryNode1 = sortList(head1);
    node *temporaryNode2 = sortList(head2);
    node *mergedHead = mergeTwoSortedLists(&temporaryNode1, &temporaryNode2);
    printf("Sorted and merged linked list:\n");
    printElements(mergedHead);
    freeLinkedList(head1);
    return 0;
}