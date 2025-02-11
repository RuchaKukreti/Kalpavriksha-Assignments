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
void inputCitations(node **head, int numberOfPapers)
{
    int citations = 0;
    for (int paper = 0; paper < numberOfPapers; paper++)
    {
        printf("Enter number of citations for paper %d :", paper);
        scanf("%d", &citations);
        addNodeToList(head, citations);
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
    node *traversalPointer1 = *head1, *traversalPointer2 = *head2, *head = NULL;
    if (!traversalPointer1)
        return traversalPointer2;
    if (!traversalPointer2)
        return traversalPointer1;
    if (traversalPointer1->data > traversalPointer2->data)
    {
        head = traversalPointer1;
        traversalPointer1 = traversalPointer1->next;
    }
    else
    {
        head = traversalPointer2;
        traversalPointer2 = traversalPointer2->next;
    }
    node *traversalPointer = head;
    while (traversalPointer1 != NULL && traversalPointer2 != NULL)
    {
        if (traversalPointer1->data > traversalPointer2->data)
        {
            traversalPointer->next = traversalPointer1;
            traversalPointer = traversalPointer->next;
            traversalPointer1 = traversalPointer1->next;
        }
        else
        {
            traversalPointer->next = traversalPointer2;
            traversalPointer = traversalPointer->next;
            traversalPointer2 = traversalPointer2->next;
        }
    }
    if (traversalPointer1)
    {
        traversalPointer->next = traversalPointer1;
    }
    else if (traversalPointer2)
    {
        traversalPointer->next = traversalPointer2;
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
node *sortCitationsInDescendingOrder(node **head)
{
    node *traversalPointer1 = NULL, *traversalPointer2 = NULL;
    if (*head == NULL || (*head)->next == NULL)
    {
        return *head;
    }
    divideLinkedlist(head, &traversalPointer1, &traversalPointer2);
    sortCitationsInDescendingOrder(&traversalPointer1);
    sortCitationsInDescendingOrder(&traversalPointer2);
    return *head = mergeTwoSortedLists(&traversalPointer1, &traversalPointer2);
}
int calculateIndex(node *head, int numberOfPapers)
{
    int hIndex = 0;
    while (head!=NULL && hIndex < numberOfPapers && head->data > hIndex && head != NULL)
    {
        hIndex += 1;
        head = head->next;
    }
    return hIndex;
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
int main()
{
    int numberOfPapers = 0, hIndex = 0;
    node *head = NULL;
    printf("Enter the number of research papers: ");
    scanf("%d", &numberOfPapers);
    inputCitations(&head, numberOfPapers);
    sortCitationsInDescendingOrder(&head);
    printf("Research Papers in decreasing order of number of citations:\n");
    printCitations(head);
    hIndex = calculateIndex(head, numberOfPapers);
    printf("H-Index for the publisher is %d", hIndex);
    freeLinkedList(head);
    return 0;
}
