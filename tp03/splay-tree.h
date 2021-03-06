/*  Name : A.Sait Tekkurt
    Date : 11.11.2020   */

#ifndef __SPLAY_TREE_H__
#define __SPLAY_TREE_H__

#include <stdio.h>
#include <stdlib.h>

#define INSERT  1
#define SEARCH  2
#define DELETE  3
#define PRINT   4
#define QUIT    5

#define CONTINUE    1
#define TERMINATE   0

#define PRINTMENU printf("Press\n\
1)Insert an element\n\
2)Search for an element\n\
3)Delete an element\n\
4)Print the tree\n\
5)Quit\n")

struct splay_node
{
    int data;
    struct splay_node *leftChild;
    struct splay_node *rightChild;
};

struct splay_node *createNode(int data);
struct splay_node *splay(struct splay_node *root, int data);
struct splay_node *insertNode(struct splay_node *root, int data);
struct splay_node *splayInsert(struct splay_node *root, int data);
struct splay_node *deleteNode(struct splay_node *root, int data);
struct splay_node *searchNode(struct splay_node *root, int data);
struct splay_node *rotateLeft(struct splay_node *node);
struct splay_node *rotateRight(struct splay_node *node);
void printPostOrder(struct splay_node *root); // postorder print function from tp02
void printLevelOrder(struct splay_node *root); // level order print function
void printGivenLevel(struct splay_node *root, int level); // helper fnc for printLevelOrder
int height(struct splay_node *node); // helper fnc for printLevelOrder
struct splay_node *findMin(struct splay_node *root); // helper fnc for delete Node

#endif /* __SPLAY_TREE_H__ */
