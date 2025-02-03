// BST (traversal : in - order, pre - order, post - order).
// insertion, deletion, searching)

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct bst
{
    struct node *root;
};

void insertRecursion(struct bst *tree, int value);
void insertIteration(struct bst *tree, int value);
void inOrderTraversal(struct node *node);
void delete(struct bst *tree, int value);
int min(struct bst *tree); // max is the same but right
struct node *search(struct node *node, int value);
void freeTree(struct node *node);

int main()
{
    struct bst *tree = malloc(sizeof(struct bst));

    // insert
    insertIteration(tree, 5);
    insertIteration(tree, 3);
    insertIteration(tree, 7);
    insertIteration(tree, 2);
    insertIteration(tree, 4);

    // traversal in order
    inOrderTraversal(tree->root);

    // search
    search(tree->root, 7);

    // min
    int mini = min(tree);
    printf("min value is: %d \n", mini);

    // delete (all cases)
    delete (tree, 2);
    printf("leaf node \n");
    inOrderTraversal(tree->root);
    insertIteration(tree, 2);
    printf("\n");
    inOrderTraversal(tree->root);

    printf("\n");

    delete (tree, 7);
    inOrderTraversal(tree->root);
    printf("leaf node \n");
    printf("\n");

    insertIteration(tree, 7);
    inOrderTraversal(tree->root);

    delete (tree, 3);
    printf("node with two children \n");

    inOrderTraversal(tree->root);
    printf("\n");

    freeTree(tree->root);
    free(tree);
    return 0;
}

void delete(struct bst *tree, int value)
{
    struct node *current = tree->root;
    struct node *parent = NULL;

    // first need to find the current and parent of value
    while (current != NULL && current->data != value)
    {
        parent = current;
        if (value < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (current == NULL)
    {
        printf("Node not found.\n");
        return;
    }

    // then we handle first case where node to remove is a leaf
    if (current->left == NULL && current->right == NULL)
    {
        printf("first case \n");
        if (parent == NULL)
        {
            tree->root = NULL;
        }
        else if (parent->left == current)
        {
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
        free(current);
    }

    // second case is for node with two children
    else
    {
        printf("second case \n");

        // find the sucessor (in order algorithm)
        struct node *successor = current->right;
        struct node *successorParent = current;

        while (successor->left != NULL)
        {
            successorParent = successor;
            successor = successor->left;
        }

        // replace current node with sucessor
        current->data = successor->data;

        // delete sucessor node (it has at most one right child)
        if (successorParent->left == successor)
        {
            successorParent->left = successor->right;
        }
        else
        {
            successorParent->right = successor->right;
        }
        free(successor);
    }

    return;
}

int min(struct bst *tree)
{
    struct node *current = tree->root;
    struct node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        current = current->left;
    }
    return parent->data;
}

struct node *search(struct node *node, int value)
{
    if (node == NULL || node->data == value)
        return node;

    search(node->left, value);
    if (node->data == value)
    {
        printf("found node %d ", node->data);
        return node;
    }
    search(node->right, value);
    return NULL;
}

void freeTree(struct node *node)
{
    if (node == NULL)
        return;

    freeTree(node->left);
    free(node);
    freeTree(node->right);
    return;
}

void inOrderTraversal(struct node *node)
{
    if (node == NULL)
        return;

    inOrderTraversal(node->left);
    printf("%d ", node->data);
    inOrderTraversal(node->right);
    return;
}

void insertIteration(struct bst *tree, int value)
{
    if (tree->root == NULL)
    {
        struct node *no = malloc(sizeof(struct node));
        no->data = value;
        no->left = NULL;
        no->right = NULL;
        tree->root = no;
        return;
    }

    struct node *current = tree->root;
    struct node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (value <= current->data)
        {
            current = current->left;
            continue;
        }
        else
        {
            current = current->right;
        }
    }
    struct node *no = malloc(sizeof(struct node));
    no->data = value;
    no->left = NULL;
    no->right = NULL;

    // check if its a left or right node
    if (value <= parent->data)
    {
        parent->left = no;
    }
    else
    {
        parent->right = no;
    }

    return;
}

void insertRecursion(struct bst *tree, int value)
{
}