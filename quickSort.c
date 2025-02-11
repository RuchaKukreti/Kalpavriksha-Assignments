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
    node *traversalNode = *head;
    while (traversalNode->next != NULL)
    {
        traversalNode = traversalNode->next;
    }
    traversalNode->next = createNode(value);
}
void inputElements(node **head, int numberOfElements)
{
    int element = 0;
    for (int iterator = 1; iterator <= numberOfElements ; iterator++)
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
node *getTail(node *head)
{
    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    return head;
}
node *partition(node *head, node *tail)
{
    node *pivot = head;
    node *previous = head, *current = head;
    while (current != tail->next)
    {
        if (current->data < pivot->data)
        {
            int temp;
            temp = current->data;
            current->data = previous->next->data;
            previous->next->data = temp;
            previous = previous->next;
        }
        current = current->next;
    }
    int currentData = pivot->data;
    pivot->data = previous->data;
    previous->data = currentData;
    return previous;
}
void quickSort(node *head, node *tail)
{
    if (head == NULL || head == tail)
        return;
    node *pivot = partition(head, tail);
    quickSort(head, pivot);
    quickSort(pivot->next, tail);
}
node *sortList(node *head)
{
    node *tail = getTail(head);
    quickSort(head, tail);
    return head;
}
node *attachOddEvenList(node *oddList, node *evenList)
{
    if (oddList == NULL)
        return evenList;
    if (evenList == NULL)
        return oddList;
    node *tail = oddList;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = evenList;
    return oddList;
}
int isOdd(int number)
{
    return (number % 2 != 0);
}
void createOddEvenList(node *head, node **oddList, node **evenList)
{
    if (head == NULL)
        return;
    node *temp = head;
    while (temp != NULL)
    {
        if (isOdd(temp->data))
        {
            addNodeToList(oddList, temp->data);
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (!isOdd(temp->data))
        {
            addNodeToList(evenList, temp->data);
        }
        temp = temp->next;
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
    node *oddList = NULL, *evenList = NULL;
    createOddEvenList(head, &oddList, &evenList);
    if (oddList)
    {
        sortList(oddList);
    }
    if (evenList)
    {
        sortList(evenList);
    }
    node *newHead = attachOddEvenList(oddList, evenList);
    printf("List after sorting all odd numbers and all even numbers in ascending order.\n");
    printElements(newHead);
    freeLinkedList(head);
    return 0;
}
