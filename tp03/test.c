/*  Name : A.Sait Tekkurt
    Date : 11.11.2020   */

#include "splay-tree.h"

int main(void)
{
    char ch;
    int in, progState, userData;
    struct splay_node *root;

    progState = CONTINUE;

    PRINTMENU; // prints menu to guide the use

    while (progState)
    {
        printf("Chose one from above\n");
        scanf("%d", &in);
        getchar();
        printf("Input is %d\n", in);

        switch (in)
        {
        case INSERT:
            printf("Data?\n");
            scanf("%d", &userData);
            getchar();
            root = insertNode(root, userData);
            break;
        case SEARCH:
            printf("Data?\n");
            scanf("%d", &userData);
            getchar();
            root = searchNode(root, userData);
            break;
        case DELETE:
            // deleteNode(NULL, 0);
            break;
        case PRINT:
            printInOrder(root);
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