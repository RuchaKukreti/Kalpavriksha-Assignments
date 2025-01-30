#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    char severity[20];
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
    while (string1[iterator] != '\0')
    {
        string1[iterator] = '\0';
        iterator++;
    }
}
node *createNode(int value, char *severity)
{
    node *temporaryNode = malloc(sizeof(node));
    if (temporaryNode == NULL)
    {
        printf("Memory allocation failed.\n");
        return temporaryNode;
    }
    temporaryNode->data = value;
    stringCopy(temporaryNode->severity, severity);
    temporaryNode->next = NULL;
    return temporaryNode;
}
void createList(node **head, int value, char *severity)
{
    if (*head == NULL)
    {
        *head = createNode(value, severity);
        return;
    }
    node *pointerToHead = *head;
    while (pointerToHead->next != NULL)
    {
        pointerToHead = pointerToHead->next;
    }
    pointerToHead->next = createNode(value, severity);
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
void inputPatients(node **head, int numberOfPatients)
{
    int patientId = 0;
    char severity[20];
    for (int patient = 1; patient < numberOfPatients + 1; patient++)
    {
        printf("Enter patient %d :", patient);
        scanf("%d", &patientId);
        printf("Enter severity :");
        scanf("%s", severity);
        if (stringCompare(severity, "Critical") || stringCompare(severity, "Serious") || stringCompare(severity, "Stable"))
        {
            createList(head, patientId, severity);
        }
        else
        {
            printf("Value for severity is not valid.\n");
            return;
        }
    }
}
void printPatients(node *head)
{
    if (head == NULL)
    {
        printf("Empty list.\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        printf("%s\n", head->severity);
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
int priority(char *severity)
{
    if (stringCompare(severity, "Critical"))
    {
        return 1;
    }
    else if (stringCompare(severity, "Serious"))
    {
        return 2;
    }
    else if (stringCompare(severity, "Stable"))
    {
        return 3;
    }
    return 0;
}
int getLength(node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}
node *sortPatients(node *head)
{
    node *current = head;
    int length = getLength(head);
    int iterator = 0;
    int swapped;
    while (iterator < length)
    {
        node *nextNode = head, *previousNode = head;
        swapped = 0;
        while (nextNode->next != NULL)
        {
            node *pointer = nextNode->next;
            if (priority(nextNode->severity) > priority(pointer->severity))
            {
                swapped = 1;
                if (nextNode == head)
                {
                    nextNode->next = pointer->next;
                    pointer->next = nextNode;
                    previousNode = pointer;
                    head = previousNode;
                }
                else
                {
                    nextNode->next = pointer->next;
                    pointer->next = nextNode;
                    previousNode->next = pointer;
                    previousNode = pointer;
                }
                continue;
            }
            previousNode = nextNode;
            nextNode = nextNode->next;
        }
        if (!swapped)
        {
            break;
        }
        iterator += 1;
    }
    return head;
}
int main()
{
    int numberOfPatients = 0;
    node *head = NULL;
    printf("Enter the number of patients: ");
    scanf("%d", &numberOfPatients);
    inputPatients(&head, numberOfPatients);
    printf("Patients List:\n");
    printPatients(head);
    printf("Sorted patients List as per priority:\n");
    node *newHead = sortPatients(head);
    printPatients(newHead);
    freeLinkedList(head);
    return 0;
}