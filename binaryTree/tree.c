#include "tree.h"

void error(void *e, char *error)
{
    if(isNull(e))
    {
        fprintf(stderr, "%s:(\n", error);
        exit(EXIT_FAILURE);
    }
}

void printTreeDeep(Tree t, int deep)
{
    if(isNull(t))
        return;
    
    printTreeDeep(t->right, deep + 1);

    for(int i = 0; i < deep; i++)
        printf("         ");

    printf("[%2d, %d, %d]\n\n", t->value, t->heightLeft, t->heightRight);

    printTreeDeep(t->left, deep + 1);
}

//Rotation Left
Tree rotationLeft(Tree t)
{
    Tree tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;

    return tmp;
}

//Rotation Right
Tree rotationRight(Tree t)
{
    Tree tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;

    return tmp;
}

//Return true si l'argument est null sinon false.
Bool isNull(void *e)
{
    return (e == NULL) ? true : false;
}
//Créer un arbre vide.
Tree createTree()
{
    return NULL;
}

//Insérer une valeur dans l'arbre.
Tree insertDeep(Tree t, int value, int *height)
{
    if(isNull(t))
    {
        t = (Tree)malloc(sizeof(struct Tree));
        error(t, "Cant create tree");
        t->value = value;
        t->heightLeft = t->heightRight = 0;
        t->left = t->right = NULL;
        *height = 1;
    }
    else if(t->value > value)
        {
            t->left = insertDeep(t->left, value, &(t->heightLeft));
            if((t->heightLeft - t->heightRight) > 1)
            t = rotationRight(t);
        }

    else 
    {
        t->right = insertDeep(t->right, value, &(t->heightRight));
        if((t->heightRight - t->heightLeft) > 1)
            t = rotationLeft(t);
    }

    *height = 1 + max(t->heightLeft, t->heightRight);

    return t;
}

Tree insert(Tree t, int value)
{
    int height = 0;
    return insertDeep(t, value, &height);
}

//Retourner true si la valeur est dans l'arbre sinon false.
Bool reseach(Tree t, int value)
{
    if(isNull(t))
        return false;
    if(t->value == value)
        return true;
    if(t->value > value)
        return reseach(t->left, value);
    else
        return reseach(t->right, value);
}

//Supprimer la valeur passée en argument et retourne l'arbre
Tree deleted(Tree t, int value)
{
    return t;
}

//Affiche l'arbre.
void printTree(Tree t)
{
    printTreeDeep(t, 0);
}

//Libère la mémoire allouer pour l'arbre.
void freeTree(Tree t)
{
    if(!isNull(t))
    {
        freeTree(t->left);
        freeTree(t->right);
    }
    free(t);
}

