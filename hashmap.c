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
void insert(row *newEntry, hash *hashMap)
{
    int indexToBeSearched = hashValue(newEntry->key);
    if (hashMap->entries[indexToBeSearched]->key == -1)
    {
        hashMap->entries[indexToBeSearched]->key = newEntry->key;
        hashMap->entries[indexToBeSearched]->value = newEntry->value;
        return;
    }
    row *temporaryNode = hashMap->entries[indexToBeSearched],*previousNode = hashMap->entries[indexToBeSearched];
    while (temporaryNode != NULL)
    {
        if(temporaryNode->key == newEntry->key){
           temporaryNode->value = newEntry->value;
           return;
        }
        previousNode=temporaryNode;
        temporaryNode = temporaryNode->next;
    }
    previousNode->next = (row *)malloc(sizeof(row *));
    previousNode->next->key = newEntry->key;
    previousNode->next->value = newEntry->value;
}
void display(hash hashMap)
{
    int isEmpty = 1;
    for (int index = 0; index < SIZE; index++)
    {
        row *temporaryNode = hashMap.entries[index];
        if (temporaryNode != NULL && hashMap.entries[index]->key != -1)
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
void search(int key, hash hashMap)
{
    int indexToBeSearched = hashValue(key);
    row *temporaryNode = hashMap.entries[indexToBeSearched];
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
void delete(int key, hash *hashMap)
{
    int indexToBeDeleted = hashValue(key);
    row *temporaryNode = hashMap->entries[indexToBeDeleted], *previousNode = hashMap->entries[indexToBeDeleted];
    if (temporaryNode == NULL)
    {
        return;
    }
    if (temporaryNode->key == key)
    {
        hashMap->entries[indexToBeDeleted] = hashMap->entries[indexToBeDeleted]->next;
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
void freeMemory(hash *hashMap)
{
    for(int slot = 0; slot < SIZE; slot++){
        row *hashNode = hashMap->entries[slot], *temporaryNode = hashMap->entries[slot];
        while (hashNode != NULL)
        {
            temporaryNode = hashNode;
            hashNode = hashNode->next;
            free(temporaryNode);
            temporaryNode=NULL;
        }
    }
    
}
void hashProgram()
{
    hash hashMap;
    hashMap.entries = (row **)malloc(SIZE * sizeof(row *));
    for (int index = 0; index < SIZE; index++)
    {
        hashMap.entries[index] = (row *)malloc(sizeof(row));
        hashMap.entries[index]->key = -1;
    }
    int numberOfOperations = 0;
    printf("Enter number of operations: ");
    scanf("%d", &numberOfOperations);
    for (int operation = 0; operation < numberOfOperations; operation++)
    {   printf("Press\n1.Insert.\n2.Search.\n3.Delete.\n4.Display.\n5.Exit\n");
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
            insert(newEntry, &hashMap);
        }
        else if (choice == 2)
        {
            printf("Enter key: ");
            int key = 0;
            scanf("%d", &key);
            search(key, hashMap);
        }
        else if (choice == 3)
        {
            printf("Enter key to be deleted: ");
            int key = 0;
            scanf("%d", &key);
            delete (key, &hashMap);
        }
        else if (choice == 4)
        {
            display(hashMap);
        }
        else if (choice == 5)
        {
            freeMemory(&hashMap);
            return;
        }
    }
}
int main()
{
    hashProgram();
    return 0;
}
