# Data Structures in C

Basic data structers implementation in C. 

---

## **Array**  
**Operations**:  
- **Insert**: Adds an element to the end (dynamic resizing with `realloc`).  
- **Remove**: Deletes a specific value (shifts elements).  
- **IndexOf**: Returns the first occurrence of a value.  
- **Merge Sort**: Sorting algorithm.  

**Time Complexity**:  
| Operation      | Time Complexity |  
|----------------|------------------|  
| Insert         | O(n)*            |  
| Remove         | O(n)             |  
| IndexOf        | O(n)             |  
| Merge Sort     | O(n log n)       |  

---

## **Queue (Linked List)**  
**Operations**:  
- **Enqueue**: Adds an element to the end of the queue.  
- **Dequeue**: Removes and returns the front element.  

**Time Complexity**:  
| Operation      | Time Complexity |  
|----------------|------------------|  
| Insert         | O(n)             |  
| Next           | O(1)             |  

---

## **Stack (Dynamic Array)**  
**Operations**:  
- **Push**: Adds an element to the top.  
- **Pop**: Removes and returns the top element.  

**Time Complexity**:  
| Operation      | Time Complexity |  
|----------------|------------------|  
| Push           | O(1)*            |  
| Pop            | O(1)*            |  

> *Amortized due to `realloc`.

---
## **Hash Table (Chaining)**  
**Operations**:  
- **Insert**: Adds a key-value pair (handles collisions via chaining).  
- **Search**: Returns the value for a key.  
- **Delete**: Removes a key-value pair.  

**Time Complexity**:  
| Operation      | Time Complexity (Avg) | Time Complexity (Worst) |  
|----------------|------------------------|-------------------------|  
| Insert         | O(1)                   | O(n)                    |  
| Search         | O(1)                   | O(n)                    |  
| Delete         | O(1)                   | O(n)                    |  

---

##  **Heap (Max-Heap)**  
**Operations**:  
- **Insert**: Adds an element to the heap.  
- **ExtractMax**: Removes and returns the maximum element.  
- **BuildHeap**: Converts an array into a valid heap.  

**Time Complexity**:  
| Operation      | Time Complexity |  
|----------------|------------------|  
| Insert         | O(log n)         |  
| ExtractMax     | O(log n)         |  
| BuildHeap      | O(n)             |  

---

## **Linked List (Singly)**  
**Operations**:  
- **Insert**: Adds an element to the end.  
- **Delete**: Removes an element by value.  
- **Traversal**: Prints all elements.  

**Time Complexity**:  
| Operation      | Time Complexity |  
|----------------|------------------|  
| Insert         | O(n)             |  
| Delete         | O(n)             |  
| Traversal      | O(n)             |  

---

## **Binary Search Tree (BST)**  
**Operations**:  
- **Insert**: Adds a value to the tree.  
- **Delete**: Removes a value (handles leaf, one-child, and two-child cases).  
- **Search**: Checks if a value exists.  
- **In-Order Traversal**: Prints elements in sorted order.  

**Time Complexity**:  
| Operation      | Time Complexity (Avg) | Time Complexity (Worst) |  
|----------------|------------------------|-------------------------|  
| Insert         | O(log n)               | O(n)                    |  
| Delete         | O(log n)               | O(n)                    |  
| Search         | O(log n)               | O(n)                    |  
| Traversal      | O(n)                   | O(n)                    |  

---

TODO: 
> graph
Graph representation (adjacency list, adjacency matrix).
Traversal algorithms (DFS, BFS).

---