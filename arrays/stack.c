// STACK (FILO) (insertion, deletion) //with array

#include <stdio.h>
#include <stdlib.h>

int *insert(int value, int *size, int *ptr);
int next(int *size, int *ptr);
void printArray(int arr[], int size);

int main()
{
    int i;
    int *ptr;
    int size = 5;

    //  Memory allocates dynamically using calloc()
    ptr = (int *)calloc(size, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Your initial STACK is \n");
        for (i = 0; i < size; i++)
        {
            ptr[i] = rand() % 20;
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }

    // INSERT
    int x;
    printf("Value to add: ");
    scanf("%d", &x);
    ptr = insert(x, &size, ptr);
    printArray(ptr, size);

    // Get next element
    int last = next(&size, ptr);
    printf("%d\n", last);

    printArray(ptr, size);

    free(ptr);
    return 0;
}

int *insert(int value, int *size, int *ptr)
{
    int *temp = ptr;
    *size = *size + 1;

    ptr = realloc(ptr, *size * sizeof(int));
    if (!ptr)
    {
        printf("realloc fail \n");
        ptr = temp;
    }
    else
    {
        printf("realloc \n");
        ptr[*size - 1] = value;
    }

    return ptr;
}

int next(int *size, int *ptr)
{
    if (*size == 0)
    {
        printf("Stack is empty!\n");
        exit(1);
    }
    int last = ptr[*size - 1];
    *size = *size - 1;

    ptr = realloc(ptr, *size * sizeof(int));
    if (!ptr)
    {
        printf("Realloc failed.\n");
        exit(1);
    }

    printf("Realloc succeeded after removal.\n");

    return last;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}