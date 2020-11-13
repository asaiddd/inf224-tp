/*  Name : A.Sait Tekkurt
    Date : 11.11.2020   */

#include "splay-tree.h"

int main(void)
{
    char ch;
    int in, progState, userData;
    struct splay_node *root = NULL;

    progState = CONTINUE;

    PRINTMENU; // prints menu to guide the use

    while (progState)
    {
        userData = 0;
        in = 0;

        printf("Chose one from above\n");
        scanf("%d", &in);
        getchar();
        printf("Input is %d\n", in);

        switch (in)
        {
        case INSERT:
            printf("What number you want to insert?\n");
            scanf("%d", &userData);
            getchar();
            printf("Inserting %d\n", userData);
            root = splayInsert(root, userData);
            break;
        case SEARCH:
            printf("What number you want to search for?\n");
            scanf("%d", &userData);
            getchar();
            printf("Searching for %d\n", userData);
            root = searchNode(root, userData);
            break;
        case DELETE:
            printf("What number you want to delete?\n");
            scanf("%d", &userData);
            getchar();
            printf("Deleting %d\n", userData);
            root = deleteNode(root, userData);
            break;
        case PRINT:
            printf("Printing the tree\n");
            printLevelOrder(root);
            printf("Finished printing\n");
            break;
        case QUIT:
            progState = TERMINATE;
            break;
        default:
            break;
        }
    }

    return 0;
}