#include <stdio.h>
#include <stdlib.h>
#define minNumberOfOperations 1
#define maxNumberOfOperations 100
typedef struct node
{
    int data;
    struct node *next;
} node;
node *create(int value)
{
    node *temp = (struct node *)malloc(sizeof(struct node));
    if (!temp)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    temp->data = value;
    temp->next = NULL;
    return temp;
}
void insertAtPosition(node **head, int position, int value)
{
    node *temp = *head;
    if (position == 1)
    {
        node *newNode = create(value);
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while (position != 2 && temp->next != NULL)
    {
        temp = temp->next;
        position--;
    }
    if (position != 2)
    {
        printf("Invalid position.\n");
        return;
    }
    node *newNode = create(value);
    newNode->next = temp->next;
    temp->next = newNode;
}
void display(node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    while (head != NULL)
    {
        printf("->%d", head->data);
        head = head->next;
    }
    printf("\n");
}
void updateAtPosition(node **head, int position, int newValue)
{
    node *temp = *head;
    if (position == 1)
    {
        if (*head == NULL)
        {
            printf("Empty list\n");
        }
        else
        {
            (*head)->data = newValue;
        }
        return;
    }
    while (position != 1 && temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
        position--;
    }
    if (position != 1)
    {
        printf("Invalid position.\n");
        return;
    }
    temp->data = newValue;
}
void deleteAtPosition(node **head, int position)
{
    if (position == 1)
    {
        if (*head == NULL)
        {
            printf("Empty list.\n");
        }
        else
        {
            node *temp = *head;
            *head = (*head)->next;
            free(temp);
            temp = NULL;
        }
        return;
    }
    node *temp = *head;
    while (position != 2 && temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
        position--;
    }
    if (position != 2)
    {
        printf("Invalid position.\n");
        return;
    }
    if (temp->next)
    {
        node *middleNode = temp->next;
        temp->next = temp->next->next;
        free(middleNode);
        middleNode = NULL;
    }
    else
    {
        printf("Invalid position.\n");
        return;
    }
}
void free_linkedlist(node **head)
{
    if (*head == NULL)
    {
        return;
    }
    node *temp = *head;
    while (temp)
    {
        struct node *t = *head;
        temp = temp->next;
        free(t);
    }
}

int main()
{
    int numberOfOperations = 0, choice = 0;
    printf("Enter the number of operations :");
    scanf("%d", &numberOfOperations);
    if (numberOfOperations < minNumberOfOperations || numberOfOperations > maxNumberOfOperations)
    {
        printf("Enter number of operations between 1 and 100.\n");
        return 0;
    }
    node *head = NULL;
    for (int operation = 0; operation < numberOfOperations; operation++)
    {
        printf("1.Insert at end.\n2.Insert at beginning.\n3.Insert at position.\n4.Display.\n5.Update at position.\n6.Delete at beginning.\n7.Delete at end.\n8.Delete at position.\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int value = 0;
            printf("Enter value of the node: ");
            scanf("%d", &value);
            int position = 1;
            struct node *temp = head;
            while (temp != NULL)
            {
                position++;
                temp = temp->next;
            }
            insertAtPosition(&head, position, value);
        }
        else if (choice == 2)
        {
            int value = 0;
            printf("Enter value of the node: ");
            scanf("%d", &value);
            insertAtPosition(&head, 1, value);
        }
        else if (choice == 3)
        {
            int position = 0, value = 0;
            printf("Enter value of the position: ");
            scanf("%d", &position);
            printf("Enter value of the node: ");
            scanf("%d", &value);
            insertAtPosition(&head, position, value);
        }
        else if (choice == 4)
        {
            display(head);
        }
        else if (choice == 5)
        {
            int position = 0, newValue = 0;
            printf("Enter value of the position: ");
            scanf("%d", &position);
            printf("Enter the new value of the node: ");
            scanf("%d", &newValue);
            updateAtPosition(&head, position, newValue);
        }
        else if (choice == 6)
        {
            deleteAtPosition(&head, 1);
        }
        else if (choice == 7)
        {
            int position = 1;
            node *temp = head;
            while (temp != NULL && temp->next != NULL)
            {
                position++;
                temp = temp->next;
            }
            deleteAtPosition(&head, position);
        }
        else if (choice == 8)
        {
            int position = 0;
            printf("Enter value of the position: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
        }
        else
        {
            printf("Enter valid choice.\n");
        }
    }
    free_linkedlist(&head);
    return 0;
}