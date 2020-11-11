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
    struct splay_node *newRoot, *leftChild;

    newRoot = node->rightChild;
    leftChild = newRoot->leftChild;

    newRoot->leftChild = node;
    node->rightChild = leftChild;

    return newRoot;
}

// rotates the subtree called node, to the right - got from tp03
struct splay_node *rotateRight(struct splay_node *node)
{
    struct splay_node *newRoot, *rightChild, *parentTmp;

    newRoot = node->leftChild;
    rightChild = newRoot->rightChild;

    newRoot->rightChild = node;
    node->leftChild = rightChild;

    return newRoot;
}

struct splay_node *splay(struct splay_node *root, int data)
{
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
            return zigZigStep(root);
        }
        else if (data < root->leftChild->data) // zag now
        {
            root->leftChild->rightChild = splay(root->leftChild->rightChild, data);
            return zigZagStep(root);
        }
        else
        {
            return zigStep(root);
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
        if (data < root->rightChild->data)
        {
            root->rightChild->rightChild = splay(root->rightChild->rightChild, data);
            return zagZagStep(root);
        }
        else if (data > root->rightChild->data) // zig now
        {
            root->rightChild->leftChild = splay(root->rightChild->leftChild, data);
            return zagZigStep(root);
        }
        else
        {
            return zagStep(root);
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

    return splay(root, data);
}

struct splay_node *deleteNode(struct splay_node *root, int data)
{return NULL;}

struct splay_node *searchNode(struct splay_node *root, int data)
{
    return splay(root, data);
}

struct splay_node *zigStep(struct splay_node *parent)
{
    if (!parent->leftChild)
    {
        return parent;
    }

    return rotateRight(parent);
}

struct splay_node *zagStep(struct splay_node *parent)
{
    if (!parent->rightChild)
    {
        return parent;
    }

    return rotateLeft(parent);
}

struct splay_node *zigZagStep(struct splay_node *grandParent)
{
    grandParent->rightChild = zigStep(grandParent->rightChild);
    return zagStep(grandParent);
}

struct splay_node *zagZigStep(struct splay_node *grandParent)
{
    grandParent->leftChild = zagStep(grandParent->leftChild);
    return zigStep(grandParent);
}

struct splay_node *zigZigStep(struct splay_node *grandParent)
{
    grandParent->rightChild = zigStep(grandParent->leftChild);
    return zigStep(grandParent);
}
struct splay_node *zagZagStep(struct splay_node *grandParent)
{
    grandParent->rightChild = zagStep(grandParent->rightChild);
    return zagStep(grandParent);
}

// inorder print function from tp02 & tp03
void printInOrder(struct splay_node *node)
{
    if (!node)
    {
        return;
    }

    printInOrder(node->leftChild);
    printf("%d\n", node->data);
    printInOrder(node->rightChild);
}