#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    char sign;
    int data;
    struct tree* left_next;
    struct tree* right_next;
    struct tree* prev;
} tree, *p_tree;

p_tree tree_ctor();
void tree_dtor_left(p_tree TREE);
void tree_dtor_right(p_tree TREE);
void tree_dtor(p_tree TREE);
void tree_put_sign_left(p_tree TREE, char sign);
void tree_put_sign_right(p_tree TREE, char sign);
void tree_put_data_left(p_tree TREE, double data);
void tree_put_data_right(p_tree TREE, double data);
int tree_int_len(char* ptr, int* ret_val);
void tree_go_forward(p_tree TREE);
void tree_put_exp(p_tree TREE, char* str);
int tree_culc(p_tree TREE);

#endif // TREE_H_INCLUDED
