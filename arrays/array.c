// Array operations (add, remove, index of, sort)

#include <stdio.h>
#include <stdlib.h>

// Function prototype
int *insertInArray(int value, int *size, int *ptr);
int *removeValueFromArray(int value, int *size, int *ptr);
int getIndexOfValue(int value, int *size, int *ptr);
void mergeSort(int arr[], int left, int right);
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
        // Cant allocate directly to a dinamic array, must do it each element by each
        printf("Memory successfully allocated using "
               "calloc.\n");

        printf("Your initial array is \n");
        for (i = 0; i < size; i++)
        {
            ptr[i] = rand() % 20; // i + 1;
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }

    // INSERT
    int x;
    printf("Value to add: ");
    scanf("%d", &x);
    ptr = insertInArray(x, &size, ptr);
    printArray(ptr, size);

    // REMOVE
    printf("\n");
    printf("remove func \n");
    ptr = removeValueFromArray(2, &size, ptr);
    printArray(ptr, size);

    // INDEX OF VALUE
    printf("\n");
    printf("return index of value %d ", x);
    int index;
    index = getIndexOfValue(x, &size, ptr);
    printf("index is: %d", index);

    // SORT ARRAY
    printf("\n");
    mergeSort(ptr, 0, size - 1);
    printArray(ptr, size);

    free(ptr);
    return 0;
}

int *insertInArray(int value, int *size, int *ptr)
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

int *removeValueFromArray(int value, int *size, int *ptr)
{
    int i;
    int *temp = ptr;
    for (i = 0; i < *size; i++)
    {
        if (ptr[i] == value)
        {
            int j;
            for (j = i; j < *size - 1; j++)
            {
                ptr[j] = ptr[j + 1];
            }
            *size = *size - 1;
            break;
        }
    }

    ptr = realloc(ptr, *size * sizeof(int));
    if (!ptr)
    {
        printf("Realloc failed.\n");
        exit(1);
    }

    printf("Realloc succeeded after removal.\n");
    return ptr;
}

int getIndexOfValue(int value, int *size, int *ptr)
{
    int index;
    int i;
    for (i = 0; i < *size; i++)
    {
        if (ptr[i] == value)
        {
            return i;
        }
    }

    return 0;
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j;
    int n1 = mid - left + 1; // Left side
    int n2 = right - mid;    // Right side
    // I can start an array with max size, cool
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }

    for (i = 0; i < n2; i++)
    {
        R[i] = arr[mid + 1 + i];
    }

    i = 0;
    j = 0;
    int k = left; // first index of subarray

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive calls, till 1 element left
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        // Split and recurse
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}