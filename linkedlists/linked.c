// Singly linked lists (insertion, deletion, traversal, reversal).

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct linkedList
{
    struct node *head;
};

void addToLinked(struct linkedList *list, struct node *node);
void printList(struct linkedList *list);
// linked list must have -> data + *next, does it need *previous?

int main()
{
    // init struct
    struct linkedList list;
    list.head = NULL; // Initialize empty list

    // Create first node
    struct node *headNode = malloc(sizeof(struct node));
    headNode->data = 5;
    headNode->next = NULL;

    list.head = headNode;

    printf("head address \n");
    printf("%p", list.head);

    // Add to linked list
    printf("\n");
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = 12;
    newNode->next = NULL;
    addToLinked(&list, newNode);

    printf("\n");
    printf("print list");
    printf("\n");
    printList(&list);

    free(newNode);
    free(headNode);
    return 0;
}

void addToLinked(struct linkedList *list, struct node *node)
{
    struct node *current = list->head;

    if (current == NULL)
    {
        list->head = node;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = node;
}

// print list
void printList(struct linkedList *list)
{
    struct node *current = list->head;

    if (current == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}