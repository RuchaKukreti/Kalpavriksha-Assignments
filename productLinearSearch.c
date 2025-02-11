#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 50
typedef struct node
{
    char data[MAX_WORD_SIZE];
    struct node *next;
} node;
void stringCopy(char *string1, char *string2)
{
    int iterator = 0;
    while (string2[iterator] != '\0')
    {
        string1[iterator] = string2[iterator];
        iterator++;
    }
    string1[iterator] = '\0';
}
node *createNode(char *value)
{
    node *temporaryNode = malloc(sizeof(node));
    if (temporaryNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return temporaryNode;
    }
    stringCopy(temporaryNode->data, value);
    temporaryNode->next = NULL;
    return temporaryNode;
}
void createList(node **head, char *value)
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
void inputProducts(node **head, int numberOfProducts)
{
    char productName[MAX_WORD_SIZE];
    for (int productNumber = 1; productNumber < numberOfProducts + 1; productNumber++)
    {
        printf("Enter product %d :", productNumber);
        scanf("%s", productName);
        createList(head, productName);
    }
}
void printProducts(node *head)
{
    if (head == NULL)
    {
        printf("Empty list.\n");
    }
    while (head != NULL)
    {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}
int stringCompare(char *string1, char *string2)
{
    int iterator = 0;
    while (string1[iterator] != '\0' && string2[iterator] != '\0')
    {
        if (string1[iterator] != string2[iterator])
        {
            return 0;
        }
        iterator++;
    }
    if (string1[iterator] == string2[iterator])
        return 1;
    return 0;
}
int linearSearchProduct(node *head, char *valueToBeSearched)
{
    int position = 1;
    while (head != NULL)
    {
        if (stringCompare(head->data, valueToBeSearched))
        {
            return position;
        }
        position++;
        head = head->next;
    }
    return -1;
}
void freeLinkedList(node *head)
{
    node *temporarayNode = head;
    while (head != NULL)
    {
        temporarayNode = head;
        head = head->next;
        free(temporarayNode);
        temporarayNode = NULL;
    }
}
int main()
{
    int numberOfProducts = 0, hIndex = 0;
    node *head = NULL;
    char productToBeSearched[MAX_WORD_SIZE];
    printf("Enter the number of products: ");
    scanf("%d", &numberOfProducts);
    inputProducts(&head, numberOfProducts);
    printf("Product list:\n");
    printProducts(head);
    printf("Enter the product to be searched: ");
    scanf("%s", productToBeSearched);
    int position = linearSearchProduct(head, productToBeSearched);
    if (position == -1)
    {
        printf("Product not found.\n");
    }
    else
    {
        printf("Product found at position: %d", position);
    }
    freeLinkedList(head);
    return 0;
}
