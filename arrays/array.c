#include <stdio.h>
#include <stdlib.h>

// Function prototype
int *insertInArray(int value, int *size, int *ptr);

int main()
{
    // address of the block created hold by this pointer
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
        // Cant allocate directly to a dinamic array, must do it each element by each
        printf("Memory successfully allocated using "
               "calloc.\n");

        printf("Your initial array is \n");
        for (i = 0; i <= size; i++)
        {
            ptr[i] = i + 1;
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }

    int x;
    printf("Value to add: ");
    scanf("%d", &x);
    insertInArray(x, &size, ptr);

    for (i = 0; i <= size; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
    return 0;
}

int *insertInArray(int value, int *size, int *ptr)
{
    // temp to hold initial array
    int *temp = ptr;
    *size = *size + 1;

    //  using realloc
    ptr = realloc(ptr, *size * sizeof(int));
    if (!ptr)
    {
        printf("Memory Re-allocation failed.");
        ptr = temp;
    }
    else
    {
        printf("Memory successfully re-allocated using "
               "realloc.\n");
        ptr[*size] = value;
    }

    return ptr;
}
