/*  Name : A.Sait Tekkurt
    Date : 11.11.2020   */

#include "splay-tree.h"

struct splay_node *createNode(int data)
{
    struct splay_node *node;

    node = (struct splay_node *) malloc(sizeof(struct splay_node));

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

// rotates the subtree called node, to the left - got from tp03
struct splay_node *rotateLeft(struct splay_node *node)
{
    struct splay_node *newRoot;

    newRoot = node->rightChild;
    node->rightChild = newRoot->leftChild;
    newRoot->leftChild = node;

    return newRoot;
}

// rotates the subtree called node, to the right - got from tp03
struct splay_node *rotateRight(struct splay_node *node)
{
    struct splay_node *newRoot;

    newRoot = node->leftChild;
    node->leftChild = newRoot->rightChild;

    newRoot->rightChild = node;

    return newRoot;
}

struct splay_node *splay(struct splay_node *root, int data)
{
    // base case
    if ((!root) || (data == root->data))
    {
        return root;
    }

    // left subtree : zig
    if (data < root->data)
    {
        if (!root->leftChild)
        {
            return root;
        }

        // zig again
        if (data < root->leftChild->data)
        {
            root->leftChild->leftChild = splay(root->leftChild->leftChild, data); // recursive call that ensures left left child is now @left-left of root
            root = rotateRight(root); // de-zig
        }
        else if (data > root->leftChild->data) // zag now
        {
            root->leftChild->rightChild = splay(root->leftChild->rightChild, data);

            if (!root->leftChild->rightChild)
            {
                root = rotateLeft(root->leftChild); // de-zag
            }
        }

        if (!root->leftChild)
        {
            return root;
        }
        else
        {
            return rotateRight(root); // de-zig
        }
    }
    else // right subtree : zag
    {
        if (!root->rightChild)
        {
            printf("Data does not exists");
            return root;
        }

        // zag again
        if (data > root->rightChild->data)
        {
            root->rightChild->rightChild = splay(root->rightChild->rightChild, data);
            root = rotateLeft(root); // de-zag
        }
        else if (data < root->rightChild->data) // zig now
        {
            root->rightChild->leftChild = splay(root->rightChild->leftChild, data);

            if (!root->rightChild->leftChild)
            {
                root->rightChild = rotateRight(root->rightChild); // de-zig
            }
        }

        if (!root->rightChild)
        {
            return root;
        }
        else
        {
            return rotateLeft(root); // de-zag
        }
    }
}

struct splay_node *insertNode(struct splay_node *root, int data)
{
    if (!root)
    {
        return (createNode(data));
    }

    if (data < root->data)
    {
        root->leftChild = insertNode(root->leftChild, data);
    }
    else if (data > root->data)
    {
        root->rightChild = insertNode(root->rightChild, data);
    }

    return root;
}

struct splay_node *splayInsert(struct splay_node *root, int data)
{
    root = insertNode(root, data);
    return splay(root, data);
}

// binary search tree delete node function - tp02
struct splay_node *deleteNode(struct splay_node *root, int data)
{
    struct splay_node *temp;

    if (!root)
    {
        printf("Could not find the %d\n", data);
        return root;
    }

    if (data < root->data)
    {
        root->leftChild = deleteNode(root->leftChild, data);
    }
    else if (data > root->data)
    {
        root->rightChild = deleteNode(root->rightChild, data);
    }
    else
    {
        if (!(root->leftChild))
        {
            temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (!(root->rightChild))
        {
            temp = root->leftChild;
            free(root);
            return temp;
        }

        temp = findMin(root->rightChild);

        root->data = temp->data;

        root->rightChild = deleteNode(root->rightChild, temp->data);
    }
    return root;
}

struct splay_node *findMin(struct splay_node *root)
{
    if (!root)
    {
        printf("Tree is empty\n");
        return NULL;
    }

    if (!root->leftChild)
    {
        return root;
    }
    else
    {
        return findMin(root->leftChild);
    }
}

struct splay_node *searchNode(struct splay_node *root, int data)
{
    return splay(root, data);
}

// postorder print function from tp02 & tp03
void printPostOrder(struct splay_node *node)
{
    if (!node)
    {
        return;
    }

    printPostOrder(node->leftChild);
    printPostOrder(node->rightChild);
    printf("%d\n", node->data);
}

void printLevelOrder(struct splay_node *root)
{
    int i, h;

    if (!root)
    {
        printf("Tree is empty, please insert elements first\n");
    }

    h = height(root);

    for (i = 1; i <= h ; i++)
    {
        printGivenLevel(root, i);
    }
}

void printGivenLevel(struct splay_node *root, int level)
{
    if (!root)
    {
        return;
    }
    if (level == 1)
    {
        printf("%d\n", root->data);
    }
    else if (level > 1)
    {
        printGivenLevel(root->leftChild, level - 1);
        printGivenLevel(root->rightChild, level -1);
    }
}

int height(struct splay_node *node)
{
    int leftHeight, rightHeight;
    if (!node)
    {
        return 0;
    }
    else
    {
        leftHeight = height(node->leftChild);
        rightHeight = height(node->rightChild);

        if (leftHeight > rightHeight)
        {
            return(leftHeight + 1);
        }
        else
        {
            return(rightHeight + 1);
        }
    }
}