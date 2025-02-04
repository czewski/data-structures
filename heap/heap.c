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

// heapify
void heapifyUp(struct Heap *heap, int index);   // used to fix the heap property - after insert
void heapifyDown(struct Heap *heap, int index); // after delete

// Basic operations
void insert(struct Heap *heap, int value);
int extractMax(struct Heap *heap);
int peek(struct Heap *heap);

// Build heap
void buildHeap(struct Heap *heap, int array[], int n);
void printHeap(struct Heap *heap);

int main()
{
    struct Heap heap;
    heap.size = 0;

    insert(&heap, 10);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 30);
    printHeap(&heap);

    return 0;
}

// Print heap (for debugging)
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