#include "tree.h"

int main(void)
{
    Tree t = createTree();

    t = insert(t, 30);
    t = insert(t, 20);
    t = insert(t, 10);
    t = insert(t, 12);
    t = insert(t, 70);
    t = insert(t, 25);
    t = insert(t, 50);
    t = insert(t, 9);
    t = insert(t, 80);
    t = insert(t, 15);
    t = insert(t, 23);
    t = insert(t, 90);
    t = insert(t, 100);
    printf("###########################################\n");
    printTree(t);
    printf("###########################################\n");
    printf("Is in tree 20 : %d\n", reseach(t, 80));
    printf("###########################################\n");

    freeTree(t);
    return EXIT_SUCCESS;
}