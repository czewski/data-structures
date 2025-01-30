// Queue (FIFO) (insertion, next) //with linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *head;
};

void insert(struct queue *list, int value);
int next(struct queue *list);
void print(struct queue *list);

int main()
{
    struct queue *list = malloc(sizeof(struct queue));
    struct node *node = malloc(sizeof(struct node));
    node->data = 5;
    list->head = node;

    // add to queue
    insert(list, 8);
    print(list);

    // next
    int x = next(list);
    printf("next element %d \n", x);
    print(list);

    free(node);
    free(list);
    return 0;
}

// next always deliver the head and update to new head
int next(struct queue *list)
{
    if (list->head == NULL)
    {
        printf("empty queue");
        exit(0);
    }

    int x;
    x = list->head->data;

    if (list->head->next != NULL)
    {
        list->head = list->head->next;
    }

    return x;
}

void insert(struct queue *list, int value)
{
    struct node *current = list->head;

    if (current == NULL)
    {
        struct node *no = malloc(sizeof(struct node));
        no->data = value;
        list->head = no;
        return;
    }

    while (current->next != NULL)
    {
        current = current->next;
    }
    struct node *no = malloc(sizeof(struct node));
    no->data = value;
    current->next = no;
}

void print(struct queue *list)
{
    struct node *current = list->head;

    if (current == NULL)
    {
        printf("queue empty.\n");
        return;
    }

    printf("queue: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        printf("%p ", current);

        current = current->next;
    }
    printf("\n");
}