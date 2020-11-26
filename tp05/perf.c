#include "perf.h"

struct treeNode
{
    int data;
    struct treeNode *leftChild;
    struct treeNode *rightChild;
};


int findMin(int *arr, int arrSize, int *minIdx)
{
    int i, min;
    min = __INT_MAX__;

    for (i = 0 ; i < arrSize ; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            *minIdx = i;
        }
    }
    
    return min;
}

// helper fnc to see whether array is filled properly
void sort(int *arr, int arrSize)
{
    int i, j, min, minIdx, endIdx;

    min = __INT_MAX__;

    arrSize;

    for (i = 0 ; i < arrSize ; i++)
    {
        endIdx = (arrSize - i) - 1;
        min = findMin(arr, (endIdx + 1), &minIdx);
        // printf("min is %d, minIdx %d, endIdx %d\n", min, minIdx, endIdx);
        
        arr[minIdx] = arr[endIdx];
        arr[endIdx] = min;
    }
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

struct treeNode *createNode(int data)
{
    struct treeNode *node;

    node = (struct treeNode *) malloc(sizeof(struct treeNode));

    if (!node)
    {
        printf("Could not created the node\n");
        return NULL;
    }

    node->leftChild = NULL;
    node->rightChild = NULL;
    node->data = data;

    return node;
}


struct treeNode *insertNode(struct treeNode *root, int data)
{
    // printf("Will add %d to tree\n", data);
    if (!root)
    {
        // printf("Initializing the tree\n");
        return (createNode(data));
    }

    if (data < root->data)
    {
        // printf("data should be on left subtree\n");
        root->leftChild = insertNode(root->leftChild, data);
    }
    else if (data > root->data)
    {
        // printf("data should be on right subtree\n");
        root->rightChild = insertNode(root->rightChild, data);
    }

    return root;
}

struct treeNode *searchNode(struct treeNode *root, int data)
{
    if (!root)
    {
        printf("Could not find element\n");
        return root;
    }    

    if (data > root->data)
    {
        return searchNode(root->rightChild, data);
    }
    else if (data < root->data)
    {
        return searchNode(root->leftChild, data);
    }
    else
    {
        // printf("Searching element %d found %d\n", data, root->data);
        return root;
    }    
}

