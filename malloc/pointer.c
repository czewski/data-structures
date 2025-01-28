#include <stdio.h>

int main()
{
    int a = 42;    // Declare an integer
    int *ptr = &a; // Pointer to the address of a

    printf("Value of a: %d\n", a);              // Prints 42
    printf("Address of a: %p\n", (void *)&a);   // Prints address of a
    printf("Pointer value: %p\n", (void *)ptr); // Prints address stored in ptr
    printf("Value via pointer: %d\n", *ptr);    // Dereferences ptr to get value of a

    return 0;
}
