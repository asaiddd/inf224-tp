#ifndef __PERF_H__
#define __PERF_H__


#include <stdio.h>
#include <stdlib.h>


void shuffle(int *array, size_t n); // stackoverflow question 6127503
void sort(int *arr, int arrSize);
int findMin(int *arr, int arrSize, int *minIdx);
struct treeNode *insertNode(struct treeNode *root, int data);
struct treeNode *createNode(int data);
struct treeNode *searchNode(struct treeNode *root, int data);
#endif /* __PERF_H__ */