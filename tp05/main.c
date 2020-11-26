#include <time.h>

#include "perf.h"

#define MAXNUM 100
#define NUM_ITER 1000

int main(void)
{
    int nums[MAXNUM];
    double numsD[MAXNUM];
    int i, j, idx, curCount;
    struct treeNode *root;
    clock_t start, end;
    double usedTime;

    root = NULL;

    // fill arr with numbers from 1 to 100
    for (i = 0; i < MAXNUM; i++)
    {
        nums[i] = i;
    }

    shuffle(nums, MAXNUM);
    
    for (i = 0; i < MAXNUM; i++)
    {
        root = insertNode(root, nums[i]);
        // printf("element %d is %d is added to binary tree\n", (i+1), nums[i]);
    }

    start = clock();
    for (i = 0; i < MAXNUM; i++)
    {    
        searchNode(root, i);
    }
    end = clock();

    usedTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("used time is %.10f, avg time is %.10f\n", usedTime, usedTime/((double)MAXNUM));
    // used time is 0.0004640, avg time is 0.0000046

    start = clock();
    for (j = 0 ; j < NUM_ITER ; j++)
    {
        for (i = 0; i < MAXNUM; i++)
        {    
            searchNode(root, i);
        }
    }
    end = clock();
    usedTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("used time is %.10f, avg time is %.10f\n", usedTime, usedTime / ((double) (MAXNUM * NUM_ITER)));
    // used time is 0.2326710, avg time is 0.0000023


    return 0;
}
