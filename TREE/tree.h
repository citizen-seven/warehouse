#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    char sign;                 //Field of sign
    int data;                  //Field of value
    struct tree* left;         //Pointer on left child
    struct tree* right;        //Pointer on right child
    struct tree* prev;         //Pointre on perents
} tree, *p_tree;

typedef struct expr
{
    char sign;
    int data;
    int nm;
} expr;

p_tree tree_ctor();
void tree_dtor(p_tree TREE);
void tree_put_sign_left(p_tree TREE, char sign);
void tree_put_sign_right(p_tree TREE, char sign);
void tree_put_data_left(p_tree TREE, int data);
void tree_put_data_right(p_tree TREE, int data);
int tree_int_len(char* ptr, int* ret_val);
void tree_go_forward(p_tree TREE);
p_tree tree_put_exp(p_tree TREE, char* str);
int tree_culc(p_tree TREE);

#endif // TREE_H_INCLUDED
