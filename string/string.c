// String manipulation (concatenation, substring, searching).

#include <stdio.h>
#include <stdlib.h>

void printString(char arr[], int size);
char *concatenate(int value, int *size, char *ptr);
char *substring(int start, int end, int *size, char *ptr);
int main()
{
    int i;
    char *ptr;
    int size = 5;

    //  Memory allocates dynamically using calloc()
    ptr = (char *)calloc(size, sizeof(char));

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
        for (i = 0; i < size; i++)
        {
            ptr[i] = 'a' + rand() % 20;
        }
        printString(ptr, size);
        printf("\n");
    }

    // Concatenate (k = a+10)
    ptr = concatenate(('a' + 10), &size, ptr);
    printString(ptr, size);

    // substring
    char *caos = substring(1, 3, &size, ptr);
    printString(caos, size);

    // searching (do we want the index of a given string?)

    free(caos);
    free(ptr);
    return 0;
}

char *concatenate(int value, int *size, char *ptr)
{
    char *temp = ptr;
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

char *substring(int start, int end, int *size, char *ptr)
{
    int i;
    int j = 0;

    if (end > *size)
    {
        return NULL;
    }

    int len = end - start + 1;
    char *temp = (char *)calloc(len + 1, sizeof(char));

    if (temp == NULL)
    {
        printf("calloc failed \n");
        exit(0);
    }

    for (i = start; i <= end; i++)
    {
        temp[j] = ptr[i];
        j++;
    }

    temp[len] = '\0';
    return temp;
}

void printString(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%c ", arr[i]);
    printf("\n");
}