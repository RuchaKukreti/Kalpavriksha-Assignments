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
void inputCitations(node **head, int numberOfPapers)
{
    int citations = 0;
    for (int paper = 0; paper < numberOfPapers; paper++)
    {
        printf("Enter number of citations for paper %d :", paper);
        scanf("%d", &citations);
        createList(head, citations);
    }
}
void printCitations(node *head)
{
    if (head == NULL)
    {
        printf("Empty list.\n");
    }
    printf("[ ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}
node *mergeTwoSortedLists(node **head1, node **head2)
{
    node *pointerToHead1 = *head1, *pointerToHead2 = *head2, *head = NULL;
    if (!pointerToHead1)
        return pointerToHead2;
    if (!pointerToHead2)
        return pointerToHead1;
    if (pointerToHead1->data > pointerToHead2->data)
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
        if (pointerToHead1->data > pointerToHead2->data)
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
void divideLinkedlist(node **head, node **head1, node **head2)
{
    if (*head == NULL)
    {
        return;
    }
    node *fastPointer = *head, *slowPointer = *head, *previousPointer = *head;
    while (fastPointer != NULL && fastPointer->next != NULL)
    {
        previousPointer = slowPointer;
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
    }
    *head1 = *head;
    *head2 = slowPointer;
    previousPointer->next = NULL;
}
node *sortCitationsInDescendingOrder(node **head, int numberOfPapers)
{
    node *pointerToHead1 = NULL, *pointerToHead2 = NULL;
    if (*head == NULL || (*head)->next == NULL)
    {
        return *head;
    }
    divideLinkedlist(head, &pointerToHead1, &pointerToHead2);
    sortCitationsInDescendingOrder(&pointerToHead1, numberOfPapers);
    sortCitationsInDescendingOrder(&pointerToHead2, numberOfPapers);
    return *head = mergeTwoSortedLists(&pointerToHead1, &pointerToHead2);
}
int calculateIndex(node *head, int numberOfPapers)
{
    int hIndex = 0;
    while (hIndex < numberOfPapers && head->data > hIndex && head != NULL)
    {
        hIndex += 1;
        head = head->next;
    }
    return hIndex;
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
    int numberOfPapers = 0, hIndex = 0;
    node *head = NULL;
    printf("Enter the number of research papers: ");
    scanf("%d", &numberOfPapers);
    inputCitations(&head, numberOfPapers);
    sortCitationsInDescendingOrder(&head, numberOfPapers);
    printf("Research Papers in decreasing order of number of citations:\n");
    printCitations(head);
    hIndex = calculateIndex(head, numberOfPapers);
    printf("H-Index for the publisher is %d", hIndex);
    freeLinkedList(head);
    return 0;
}