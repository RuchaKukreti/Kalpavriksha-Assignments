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
    node *pointerToHead = *head;
    while (pointerToHead->next != NULL)
    {
        pointerToHead = pointerToHead->next;
    }
    pointerToHead->next = createNode(value);
}
void inputPagesOfBooks(node **head, int numberOfBooks)
{
    int numberOfPages = 0;
    for (int book = 1; book <= numberOfBooks; book++)
    {
        printf("Enter number of pages for book %d :", book);
        scanf("%d", &numberOfPages);
        addNodeToList(head, numberOfPages);
    }
}
void printBooks(node *head)
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
void swap(int *value1, int *value2)
{
    int temporary = *value1;
    *value1 = *value2;
    *value2 = temporary;
}
node *sortBooksByNumberOfPages(node *head, int numberOfBooks)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *sortedHead = head;
    for (int books = 0; books < numberOfBooks - 1; books++)
    {
        node *current = head;
        node *next = head->next;
        while (next != NULL)
        {
            if (current->data > next->data)
            {
                swap(&current->data, &next->data);
            }
            current = current->next;
            next = next->next;
        }
    }
    return sortedHead;
}
int findNumberOfStudents(node *head, int numberOfPages)
{
    int studentCount = 1, pages = 0;
    while (head != NULL)
    {
        if (pages + head->data <= numberOfPages)
        {
            pages += head->data;
        }
        else
        {
            studentCount++;
            pages = head->data;
        }
        head = head->next;
    }
    return studentCount;
}
int max(int value1, int value2)
{
    if (value1 > value2)
        return value1;
    return value2;
}
void calculateMinAndMaxValue(node *head, int *minValue, int *maxValue)
{
    int sumOfPagesOfAllBooks = 0;
    while (head != NULL)
    {
        *minValue = max(*minValue, head->data);
        sumOfPagesOfAllBooks += head->data;
        head = head->next;
    }
    *maxValue = sumOfPagesOfAllBooks;
}
int binarySearch(node *head, int minValue, int maxValue, int numberOfStudents)
{
    while (minValue <= maxValue)
    {
        int mid = minValue + (maxValue - minValue) / 2;
        int calculatedNumberOfStudents = findNumberOfStudents(head, mid);
        if (calculatedNumberOfStudents <= numberOfStudents)
        {
            maxValue = mid - 1;
        }
        else
        {
            minValue = mid + 1;
        }
    }
    return minValue;
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
    int numberOfBooks = 0, numberOfStudents = 0, minValue = 0, maxValue = 0;
    node *head = NULL;
    printf("Enter the number of books: ");
    scanf("%d", &numberOfBooks);
    inputPagesOfBooks(&head, numberOfBooks);
    node *sortedHead = sortBooksByNumberOfPages(head, numberOfBooks);
    printf("Books in sorted order by number of pages:\n");
    printBooks(sortedHead);
    printf("Enter the number of student: ");
    scanf("%d", &numberOfStudents);
    calculateMinAndMaxValue(sortedHead, &minValue, &maxValue);
    int maximumNumberOfPages = binarySearch(sortedHead, minValue, maxValue, numberOfStudents);
    printf("The minimized value of maximum number of pages assigned to any student is: %d", maximumNumberOfPages);
    freeLinkedList(head);
    return 0;
}
