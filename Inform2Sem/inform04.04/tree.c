#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct Node Node;
struct Node{Data val; Node* left; Node* right;};

void tree_print_symmetric(Node* tree);
Node* tree_add(Node*, Data);
void tree_destroy(Node* tree);
void tree_print_primoy(Node* tree);

int main()
    {
    Node* tree = NULL;
    Data x;
    while (scanf("%d", &x))
        tree = tree_add(tree, x);
    tree_print_symmetric(tree);
    return 0;
    }


void tree_print_symmetric(Node* tree)
    {
    if (tree == NULL)
        return;
    tree_print_symmetric(tree-> left);
    printf("%d   ", tree -> val);
    tree_print_symmetric(tree -> right);
    }

void print_tree_primoy(Node* tree)
    {
    if (tree == NULL)
        return;
    printf("%d   ", tree -> val);
    tree_print_primoy(tree-> left);
    tree_print_primoy(tree -> right);
    }

void tree_destroy(Node* tree)
    {
    if (tree != NULL)
        {
        tree_destroy(tree -> left);
        tree_destroy(tree -> right);
        free(tree);
        }
    }

Node* tree_add(Node* tree, Data x)
    {
    if (tree == NULL)
        {
        tree = (Node*) malloc(sizeof(Node));
        tree -> left = NULL;
        tree -> right = NULL;
        tree -> val = x;
        }
    else 
        {
        if (x < tree -> val)
            tree -> left = tree_add(tree -> left, x);
        else
            if (x > tree -> val)
                tree -> right = tree_add(tree -> right, x);
        }
    return tree;
    }