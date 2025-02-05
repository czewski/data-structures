// heap (Min heap, max, heap.Heapify, insertion, deletion, build heap
// get parent, get left child, get right child
// https://pages.cs.wisc.edu/~mcw/cs367/lectures/heaps.html

#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    int arr[100]; // max size = 100
    int size;
};

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct Heap *heap, int index);   // used to fix the heap property - after insert
void heapifyDown(struct Heap *heap, int index); // after delete
void insert(struct Heap *heap, int value);
int extractMax(struct Heap *heap);
void buildHeap(struct Heap *heap, int array[], int n);
void printHeap(struct Heap *heap);

int main()
{
    struct Heap heap;
    heap.size = 0;

    int array[] = {5, 3, 8, 1, 9};
    int n = sizeof(array) / sizeof(array[0]);
    buildHeap(&heap, array, n);
    printHeap(&heap);

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    printHeap(&heap);

    extractMax(&heap);
    printHeap(&heap);
    return 0;
}

void printHeap(struct Heap *heap)
{
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

void insert(struct Heap *heap, int value)
{
    if (heap->size >= 100)
    {
        printf("full \n");
        return;
    }

    // add in the end
    heap->arr[heap->size] = value;
    heap->size++;

    heapifyUp(heap, heap->size - 1);
}

// heapify will move the element up until right position
void heapifyUp(struct Heap *heap, int index)
{
    // compare the current node with its parent
    // if the parent is smaller, swap the current node with its parent
    while (index > 0 && heap->arr[parent(index)] < heap->arr[index])
    {
        swap(&heap->arr[parent(index)], &heap->arr[index]);
        index = parent(index);
    }
}

void heapifyDown(struct Heap *heap, int index)
{
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < heap->size && heap->arr[left] > heap->arr[maxIndex])
    {
        maxIndex = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[maxIndex])
    {
        maxIndex = right;
    }

    if (index != maxIndex)
    {
        swap(&heap->arr[index], &heap->arr[maxIndex]);
        heapifyDown(heap, maxIndex);
    }
}

// remove root
int extractMax(struct Heap *heap)
{
    if (heap->size <= 0)
    {
        printf("empty \n");
        return -1;
    }

    int max = heap->arr[0];

    // replace the root with the last element
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);
    return max;
}

void buildHeap(struct Heap *heap, int array[], int n)
{
    if (n > 100)
    {
        printf("bigger than heap size \n");
        return;
    }

    // copy the array into the heap
    for (int i = 0; i < n; i++)
    {
        heap->arr[i] = array[i];
    }
    heap->size = n;

    // heapify all non-leaf nodes
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapifyDown(heap, i);
    }
}