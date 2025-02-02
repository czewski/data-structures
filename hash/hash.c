// hash table (insert, search, delete)
#include <stdio.h>
#include <stdlib.h>
// keys -> values
// Structure:

struct node
{
    int key;
    int value;
    struct node *next; // Linked list principle for collisions
};

struct hash
{
    struct node *buckets[100]; // Maximum of 100 elements
};

int hash(int key)
{
    return key % 100;
}

void insert(struct hash *hashtable, int key, int value);
int search(struct hash *hashtable, int key);
void delete(struct hash *hashtable, int key);
void printHashTable(struct hash *hashtable)
{
    for (int i = 0; i < 100; i++)
    {
        struct node *current = hashtable->buckets[i];
        if (current != NULL)
        {
            printf("Bucket %d: ", i);
            while (current != NULL)
            {
                printf("(%d, %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

int main()
{
    struct hash *hashtable = malloc(sizeof(struct hash));
    if (hashtable == NULL)
    {
        printf("malloc fail \n");
        exit(9);
    }

    // init nulll
    for (int i = 0; i < 100; i++)
    {
        hashtable->buckets[i] = NULL;
    }

    // insert
    insert(hashtable, 42, 100);
    insert(hashtable, 142, 200);
    insert(hashtable, 242, 300);
    printHashTable(hashtable);

    // search
    int value = search(hashtable, 42);
    printf("%d \n", value);

    // del
    delete (hashtable, 142);
    printHashTable(hashtable);

    free(hashtable);
    return 0;
}

void insert(struct hash *hashtable, int key, int value)
{
    int index = hash(key);
    struct node *no = malloc(sizeof(struct node));
    if (no == NULL)
    {
        printf("malloc fail \n");
        return;
    }

    no->key = key;
    no->value = value;
    no->next = hashtable->buckets[index];
    hashtable->buckets[index] = no;

    return;
}

int search(struct hash *hashtable, int key)
{
    int index = hash(key);

    if (hashtable->buckets[index] == NULL)
    {
        printf("key not found");
        return -1;
    }

    struct node *n = hashtable->buckets[index];
    while (n != NULL)
    {
        if (n->key == key)
        {
            return n->value;
        }
        n = n->next;
    }

    return -1;
}

void delete(struct hash *hashtable, int key)
{
    int index = hash(key);
    struct node *current = hashtable->buckets[index];
    struct node *prev = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (prev == NULL) // deleting the head node
            {
                hashtable->buckets[index] = current->next;
            }
            else
            {
                // deleting a middle/tail node
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("key %d not found \n", key);
}