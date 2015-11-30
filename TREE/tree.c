#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"

p_tree tree_ctor()
{
    p_tree tmp = (p_tree) malloc (sizeof(tree));
    tmp -> left_next = NULL;
    tmp -> right_next = NULL;
    tmp -> prev = NULL;
    tmp -> data = 0;
    return tmp;
}

void tree_dtor_left(p_tree TREE)
{
    TREE -> left_next -> data = 0;
    TREE -> left_next -> sign = 0;
    TREE -> left_next = NULL;
}

void tree_dtor_right(p_tree TREE)
{
    TREE -> right_next -> data = 0;
    TREE -> right_next -> sign = 0;
    TREE -> right_next = NULL;
}

void tree_dtor(p_tree TREE)
{
    tree_dtor_left(TREE);
    tree_dtor_right(TREE);
    TREE = NULL;
}

void tree_put_sign_left(p_tree TREE, char sign)
{
    p_tree tmp = tree_ctor();
    TREE -> left_next = tmp;
    tmp -> prev = TREE;
    tmp -> sign = sign;
    tmp -> data = 0;
}

void tree_put_sign_right(p_tree TREE, char sign)
{
    p_tree tmp = tree_ctor();
    TREE -> right_next = tmp;
    tmp -> prev = TREE;
    tmp -> sign = sign;
    tmp -> data = 0;
}

void tree_put_data_left(p_tree TREE, double data)
{
    p_tree tmp = tree_ctor();
    TREE -> left_next = tmp;
    tmp -> prev = TREE;
    tmp -> data = data;
}

void tree_put_data_right(p_tree TREE, double data)
{
    p_tree tmp = tree_ctor();
    TREE -> right_next = tmp;
    tmp -> prev = TREE;
    tmp -> data = data;
}

int tree_int_len(char* ptr, int* ret_val)
{
    int j = 0;
    *ret_val = 0;
    for(j = 0; ; j++)
    {
        if ((*(ptr+j) >= '*') && (*(ptr+j) <= '/'))
            break;
    }
    int k = 0;
    for (k = j - 1; k >= 0; k--)
    {
        *ret_val += (ptr[k] - '0') * pow(10, k);
    }
    return j;
}

void tree_go_forward(p_tree TREE)
{
    p_tree tmp = tree_ctor();
    TREE -> right_next = tmp;
    tmp -> prev = TREE;
    TREE = tmp;
}

void tree_put_exp(p_tree TREE, char* str)
{
    char* ptr = str;
    int tmp_int = 0, tmp_int_left = 0, tmp_int_right = 0;
    //char tmp_char;
    int length = strlen(str);
    int i = 0;
    while(i < length)
    {
        if ((ptr[i] >= '*') && (ptr[i] <= '/'))
        {
            switch(ptr[i])
            {
                case '+':
                {
                    TREE -> data = 0;
                    TREE -> sign = ptr[i];
                    tree_go_forward(TREE);
                    i++;
                    break;
                }
                case '-':
                {
                    TREE -> data = 0;
                    TREE -> sign = ptr[i];
                    tree_go_forward(TREE);
                    i++;
                    break;
                }
                case '*':
                {
                    i++;
                    tmp_int_left = TREE -> left_next -> data;
                    i += tree_int_len(ptr + i, &tmp_int_right);
                    tmp_int = tmp_int_left * tmp_int_right;
                    TREE -> data = tmp_int;
                    tree_dtor_left(TREE);
                    break;
                }
                case '/':
                {
                    i++;
                    tmp_int_left = TREE -> data;
                    i += tree_int_len(ptr + i, &tmp_int_right);
                    tmp_int = tmp_int_left / tmp_int_right;
                    TREE -> data = tmp_int;
                    tree_dtor_left(TREE);
                    break;
                }
            }
        }
        else if ((ptr[i] >= '0') && (ptr[i] <= '9'))
        {
            i += tree_int_len(ptr + i, &tmp_int);
            tree_put_data_left(TREE, tmp_int);
        }
    }
}

int tree_culc(p_tree TREE)
{
    if ( ( (TREE -> left_next) || (TREE -> right_next) ) && (TREE -> sign == '+') )
        return (tree_culc(TREE -> left_next) + tree_culc(TREE -> right_next));

    else if ( ( (TREE -> left_next) || (TREE -> right_next) ) && (TREE -> sign == '-') )
        return (tree_culc(TREE -> left_next) - tree_culc(TREE -> right_next));

    else if ( !(TREE -> left_next) && !(TREE -> right_next) )
        return TREE -> data;
}


