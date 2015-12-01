#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"

p_tree tree_ctor() //This function make a peak of tree
{
    p_tree tmp = (p_tree) malloc (sizeof(tree));
    tmp -> left_next = NULL;
    tmp -> right_next = NULL;
    tmp -> prev = NULL;
    tmp -> data = 0;
    return tmp;
}

void tree_dtor_left(p_tree TREE) //This function delete and destroy left subtree
{
    TREE -> left_next -> data = 0;
    TREE -> left_next -> sign = 0;
    free(TREE->left_next);
    TREE -> left_next = NULL;
}

void tree_dtor_right(p_tree TREE) //This function delete and destroy right subtree
{
    TREE -> right_next -> data = 0;
    TREE -> right_next -> sign = 0;
    free(TREE->left_next);
    TREE -> right_next = NULL;
}

void tree_dtor(p_tree TREE) //This function delete and destroy tree
{
    tree_dtor_left(TREE);
    tree_dtor_right(TREE);
    free(TREE);
    TREE = NULL;
}

void tree_put_sign_left(p_tree TREE, char sign) //This function put sign into field "sign" of the left child of tree
{
    TREE -> left_next = tree_ctor();
    TREE -> left_next -> prev = TREE;
    TREE -> left_next -> sign = sign;
    TREE -> left_next -> data = 0;
}

void tree_put_sign_right(p_tree TREE, char sign) //This function put sign into field "sign" of the right child of tree
{
    TREE -> right_next = tree_ctor();
    TREE -> right_next -> prev = TREE;
    TREE -> right_next -> sign = sign;
    TREE -> right_next -> data = 0;
}

void tree_put_data_left(p_tree TREE, int data) //This function put value into field "data" of the left child of tree
{
    TREE -> left_next = tree_ctor();
    TREE -> left_next -> prev = TREE;
    TREE -> left_next -> data = data;
}

void tree_put_data_right(p_tree TREE, int data) //This function put value into field "data" of the right child of tree
{
    TREE -> right_next = tree_ctor();
    TREE -> right_next -> prev = TREE;
    TREE -> right_next -> data = data;
}

int tree_int_len(char* ptr, int* ret_val) //This function return number of digits, who situated betwen 2 sign and consider it
{
    int j = 0;
    *ret_val = 0;
    for(j = 0; ; j++)
    {
        if ((*(ptr+j) <= '0') || (*(ptr+j) >= '9'))
            break;
    }
    int k = 0;
    for (k = j - 1; k >= 0; k--)
    {
        *ret_val += (*(ptr+k) - '0') * pow(10, j - k - 1);
    }
    return j;
}

void tree_go_forward(p_tree* TREE) //This function move pointer on the right child
{
    p_tree tmp = *TREE;
    *TREE = tree_ctor();
    tmp->right_next = *TREE;
}

void tree_put_exp(p_tree TREE, char* str) //This function convert string into tree
{
    char* ptr = str;
    int tmp_int = 0, tmp_int_left = 0, tmp_int_right = 0;
    int length = strlen(str);
    int i = 0;
    while(i < length - 1)
    {
        if ((ptr[i] >= '*') && (ptr[i] <= '/'))
        {
            switch(ptr[i])
            {
                case '+': //If '+' then put '+' into field "sign"  of tree
                {
                    TREE -> data = 0;
                    TREE -> sign = ptr[i];
                    tree_go_forward(&TREE);
                    i++;
                    break;
                }
                case '-': //If '-' then put '-' into field "sign"  of tree
                {
                    TREE -> data = 0;
                    TREE -> sign = ptr[i];
                    tree_go_forward(&TREE);
                    i++;
                    break;
                }
                case '*': //If '*' then consider math mathematical expression and put it instead last number
                {
                    i++;
                    tmp_int_left = TREE -> left_next -> data;
                    i += tree_int_len(ptr + i, &tmp_int_right);
                    tmp_int = tmp_int_left * tmp_int_right;
                    TREE -> data = tmp_int;
                    tree_dtor_left(TREE);
                    break;
                }
                case '/': //If '/' then consider math mathematical expression and put it instead last number
                {
                    i++;
                    tmp_int_left = TREE -> left_next -> data;
                    i += tree_int_len(ptr + i, &tmp_int_right);
                    tmp_int = tmp_int_left / tmp_int_right;
                    TREE -> data = tmp_int;
                    tree_dtor_left(TREE);
                    break;
                }
            }
        }
        else if ((ptr[i] >= '0') && (ptr[i] <= '9')) //If number then put it into filed "data" of the left child of tree
        {
            i += tree_int_len(ptr + i, &tmp_int);
            tree_put_data_left(TREE, tmp_int);
        }
    }
}

int tree_culc(p_tree TREE) //This function consider math mathematical expression
{
    if ( TREE->left_next && TREE->right_next && (TREE->sign == '+') )
    {
        return (tree_culc(TREE->left_next) + tree_culc(TREE->right_next));
    }
    else if ( TREE->left_next && TREE->right_next && (TREE -> sign == '-') )
    {
      return (tree_culc(TREE->left_next) - tree_culc(TREE->right_next));
    }
    else if ( !(TREE -> left_next) && !(TREE -> right_next) )
    {
      return TREE -> data;
    }
    return 0xBAD;
}


