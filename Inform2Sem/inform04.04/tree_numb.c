#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef int Data;
typedef struct Node Node;
struct Node {
    Data val;
    Node *left;
    Node *right;
    int level;
};

Node *tree_add(Node * tree, Data x, int Level);
void tree_print(Node * tree);
void tree_destroy(Node * tree);
void depth(Node * tree, int *max, int *cur_depth);
void LeavesOfTree(Node * tree);
void width_print(Node * tree);
int HeightOfTree(Node * node);
void tree_print_level(Node * tree, int Level);
int Balance_checking(Node * tree);
int main()
{
    Node *tree = NULL;
    Data x;
    int Level;
    do {
        scanf("%d", &x);
        if (x == 0)
            break;
        tree = tree_add(tree, x, -1);
    }
    while (1);
    width_print(tree);
    //scanf("%d", &Level);
    //tree_print(tree);
    //tree_print_level(tree, Level);
    //if (Balance_checking(tree) == 0)
    //printf("YES");
    //else
    //printf("NO");
    tree_destroy(tree);
}

Node *tree_add(Node * tree, Data x, int Level)
{
    if (tree == NULL) {
        tree = (Node *) malloc(sizeof(Node));
        tree->left = NULL;
        tree->right = NULL;
        tree->val = x;
        tree->level = Level + 1;
    } else {
        if (x < tree->val)
            tree->left = tree_add(tree->left, x, tree->level);
        else if (x > tree->val)
            tree->right = tree_add(tree->right, x, tree->level);
    }
    return tree;
}

void tree_print(Node * tree)
{
    if (tree == NULL)
        return;
    tree_print(tree->left);
    printf("%d (level = %d)   ", tree->val, tree->level);
    tree_print(tree->right);
}

void tree_print_level(Node * tree, int Level)
{
    if (tree == NULL)
        return;
    tree_print_level(tree->left, Level);
    if (tree->level == Level)
        printf("%d ", tree->val);
    tree_print_level(tree->right, Level);
}

void width_print(Node * tree)
{
    for (int i = 0; i <= HeightOfTree(tree); i++) {
        tree_print_level(tree, i);
    }
}

void tree_destroy(Node * tree)
{
    if (tree != NULL) {
        tree_destroy(tree->left);
        tree_destroy(tree->right);
        free(tree);
    }
}

void depth(Node * tree, int *max, int *cur_depth)
{
    if (tree != NULL) {
        (*cur_depth)++;
        printf("cur_depth = %d\n", *cur_depth);
    } else {
        if (*cur_depth > *max) {
            *max = *cur_depth;
            printf("max = %d", *max);
        }
        (*cur_depth)--;
        return;
    }
    depth(tree->left, max, cur_depth);
    depth(tree->right, max, cur_depth);
}

int HeightOfTree(Node * tree)
{
    if (tree == NULL)
        return 0;
    int left, right;
    if (tree->left != NULL)
        left = HeightOfTree(tree->left);
    else
        left = 0;
    if (tree->right != NULL)
        right = HeightOfTree(tree->right);
    else
        right = 0;
    int max = left > right ? left : right;
    return max + 1;
}

void LeavesOfTree(Node * tree)
{
    if (tree == NULL)
        return;
    if ((tree->left == NULL) && (tree->right == NULL)) {
        printf("%d ", tree->val);
        return;
    }
    LeavesOfTree(tree->left);
    LeavesOfTree(tree->right);
}

int Balance_checking(Node * tree)
{
    if (tree == NULL)
        return 0;
    if (fabs(HeightOfTree(tree->right) - HeightOfTree(tree->left)) <= 1) {
        if (Balance_checking(tree->left) == 0)
            if (Balance_checking(tree->right) == 0)
                return 0;
            else
                return 1;
        else
            return 1;
    } else
        return 1;
}
