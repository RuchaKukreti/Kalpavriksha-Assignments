#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
typedef struct row
{
    int key;
    int value;
    struct row *next;
} row;
typedef struct hash
{
    struct row **entries;
} hash;
int hashValue(int value)
{
    return value % SIZE;
}
void insert(row *newEntry, hash *hashmap)
{
    int indexToBeSearched = hashValue(newEntry->key);
    if (hashmap->entries[indexToBeSearched]->key == -1)
    {
        hashmap->entries[indexToBeSearched]->key = newEntry->key;
        hashmap->entries[indexToBeSearched]->value = newEntry->value;
        return;
    }
    row *temporaryNode = hashmap->entries[indexToBeSearched];
    while (temporaryNode != NULL && temporaryNode->next != NULL)
    {
        temporaryNode = temporaryNode->next;
    }
    temporaryNode->next = (row *)malloc(sizeof(row *));
    temporaryNode->next->key = newEntry->key;
    temporaryNode->next->value = newEntry->value;
}
void display(hash hashmap)
{
    int isEmpty = 1;
    for (int index = 0; index < SIZE; index++)
    {
        row *temporaryNode = hashmap.entries[index];
        if (temporaryNode != NULL && hashmap.entries[index]->key != -1)
        {
            isEmpty = 0;
            printf("Index:%d ", index);
            while (temporaryNode != NULL)
            {
                if (temporaryNode->next == NULL)
                {
                    printf("(%d:%d)", temporaryNode->key, temporaryNode->value);
                }
                else
                {
                    printf("(%d:%d)->", temporaryNode->key, temporaryNode->value);
                }
                temporaryNode = temporaryNode->next;
            }
            printf("\n");
        }
    }
    if (isEmpty)
    {
        printf("Empty.\n");
    }
}
void search(int key, hash hashmap)
{
    int indexToBeSearched = hashValue(key);
    row *temporaryNode = hashmap.entries[indexToBeSearched];
    while (temporaryNode != NULL)
    {
        if (temporaryNode->key == key)
        {
            printf("value:%d\n", temporaryNode->value);
            return;
        }
        temporaryNode = temporaryNode->next;
    }
    printf("Not found.\n");
}
void delete(int key, hash *hashmap)
{
    int indexToBeDeleted = hashValue(key);
    row *temporaryNode = hashmap->entries[indexToBeDeleted], *previousNode = hashmap->entries[indexToBeDeleted];
    if (temporaryNode == NULL)
    {
        return;
    }
    if (temporaryNode->key == key)
    {
        hashmap->entries[indexToBeDeleted] = hashmap->entries[indexToBeDeleted]->next;
        temporaryNode->next = NULL;
        free(temporaryNode);
        return;
    }
    while (temporaryNode != NULL)
    {
        if (temporaryNode->key == key)
        {
            previousNode->next = temporaryNode->next;
            break;
        }
        previousNode = temporaryNode;
        temporaryNode = temporaryNode->next;
    }
    if (temporaryNode)
    {
        temporaryNode->next = NULL;
        free(temporaryNode);
    }
    else
    {
        printf("Not found\n");
    }
}
void hashProgram()
{
    hash hashmap;
    hashmap.entries = (row **)malloc(SIZE * sizeof(row *));
    for (int index = 0; index < SIZE; index++)
    {
        hashmap.entries[index] = (row *)malloc(sizeof(row));
        hashmap.entries[index]->key = -1;
    }
    int numberOfOperations = 0;
    printf("Enter number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int operation = 0; operation < numberOfOperations; operation++)
    {
        int choice = 0;
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int value = 0, key = 0;
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            row *newEntry = (row *)malloc(sizeof(row));
            newEntry->key = key;
            newEntry->value = value;
            newEntry->next = NULL;
            insert(newEntry, &hashmap);
        }
        else if (choice == 2)
        {
            printf("Enter key: ");
            int key = 0;
            scanf("%d", &key);
            search(key, hashmap);
        }
        else if (choice == 3)
        {
            printf("Enter key to be deleted: ");
            int key = 0;
            scanf("%d", &key);
            delete (key, &hashmap);
        }
        else if (choice == 4)
        {
            display(hashmap);
        }
        else if (choice == 5)
        {
            return;
        }
    }
}
int main()
{
    hashProgram();
    return 0;
}