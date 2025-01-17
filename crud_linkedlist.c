#include <stdio.h>
#include <stdlib.h>
struct node
{
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *create(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = value;
    temp->next = NULL;
    return temp;
}
void insertAtPosition(int position, int value)
{
    struct node *temp = head, *newnode = create(value);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    if (position == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    while (temp->next != NULL && position > 2)
    {
        temp = temp->next;
        position--;
    }
    if (position != 3)
    {
        printf("Invalid position.\n");
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void insertAtBeginning(int value)
{
    insertAtPosition(1, value);
}
void insertAtEnd(int value)
{
    struct node *temp = head, *newnode = create(value);
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void display()
{
    struct node *temp = head;
    if (temp == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (temp != NULL && temp != NULL)
    {
        printf("->%d", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
void updateAtPosition(int position, int newValue)
{
    if (head == NULL)
        return;
    struct node *temp = head;
    if (position == 1)
    {
        head->val = newValue;
        return;
    }
    for (int row = 1; row < position - 1; row++)
    {
        if (temp != NULL)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf("The position is not present.\n");
        return;
    }
    temp->next->val = newValue;
}
void deleteAtBeginning()
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd()
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        head = NULL;
        return;
    }
    if (position == 1 && head->next == NULL)
    {
        head = head->next;
        return;
    }
    struct node *temp = head, *prev = head;
    while (position > 1 && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        position--;
    }
    if (position != 1)
    {
        printf("Invalid position\n");
    }
    else
    {
        if (temp == NULL)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = temp->next;
            free(temp);
        }
    }
}
int main()
{
    int num = 0, choice = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &choice);
        if (choice == 1)
        {
            int value = 0;
            scanf("%d", &value);
            insertAtEnd(value);
        }
        else if (choice == 2)
        {
            int value = 0;
            scanf("%d", &value);
            insertAtBeginning(value);
        }
        else if (choice == 3)
        {
            int position = 0, value = 0;
            scanf("%d%d", &position, &value);
            insertAtPosition(position, value);
        }
        else if (choice == 4)
        {
            display();
        }
        else if (choice == 5)
        {
            int position = 0, newValue = 0;
            scanf("%d%d", &position, &newValue);
            updateAtPosition(position, newValue);
        }
        else if (choice == 6)
        {
            deleteAtBeginning();
        }
        else if (choice == 7)
        {
            deleteAtEnd();
        }
        else if (choice == 8)
        {
            int position = 0;
            scanf("%d", &position);
            deleteAtPosition(position);
        }
        else
        {
            break;
        }
    }
    return 0;
}