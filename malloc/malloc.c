#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pointer = (int *)calloc(0, 0);
    if (pointer == NULL)
    {
        printf("Null pointer \n");
    }
    else
    {
        printf("Address = %p", (void *)pointer);
    }
    free(pointer);
    return 0;
}
// ptr = (cast-type*) malloc(byte-size);