#ifndef __TREE__H__
#define __TREE__H__

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Tree 
{
    int value;
    int heightLeft, heightRight;
    struct Tree *left;
    struct Tree *right;
}*Tree;

typedef enum 
{
    false,
    true

}Bool;
Tree createTree();
Tree insert(Tree t, int value);
Tree deleted(Tree t, int value);
Bool reseach(Tree t, int value);
Bool isNull(void *);
void printTree(Tree t);
void freeTree(Tree t);

#endif