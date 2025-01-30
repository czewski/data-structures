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
void removeElement(struct linkedList *list, int number);
void printList(struct linkedList *list);

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

    // Remove element
    removeElement(&list, 12);

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

void removeElement(struct linkedList *list, int number)
{
    struct node *current = list->head;
    struct node *last = list->head;

    if (current == NULL)
    {
        return;
    }

    while (current->data != 0)
    {
        if (current->data == number)
        {
            last->next = current->next;
            return;
        }
        last = current;
        current = current->next;
    }
    return;
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
        printf("%p ", current);

        current = current->next;
    }
    printf("\n");
}