#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tree.h"

p_tree tree_ctor() //This function make a peak of tree
{
    p_tree tmp = (p_tree) malloc (sizeof(tree));
    tmp -> left = NULL;
    tmp -> right = NULL;
    tmp -> prev = NULL;
    tmp -> data = 0;
    return tmp;
}

void tree_dtor(p_tree TREE) //This function delete and destroy tree
{
    if (TREE -> left)
        tree_dtor(TREE -> left);
    if (TREE -> right)
        tree_dtor(TREE -> right);
    free(TREE);
}

void tree_put_sign_left(p_tree TREE, char sign) //This function put sign into field "sign" of the left child of tree
{
    TREE -> left = tree_ctor();
    TREE -> left -> prev = TREE;
    TREE -> left -> sign = sign;
    TREE -> left -> data = 0;
}

void tree_put_sign_right(p_tree TREE, char sign) //This function put sign into field "sign" of the right child of tree
{
    TREE -> right = tree_ctor();
    TREE -> right -> prev = TREE;
    TREE -> right -> sign = sign;
    TREE -> right -> data = 0;
}

void tree_put_data_left(p_tree TREE, int data) //This function put value into field "data" of the left child of tree
{
    TREE -> left = tree_ctor();
    TREE -> left -> prev = TREE;
    TREE -> left -> data = data;
}

void tree_put_data_right(p_tree TREE, int data) //This function put value into field "data" of the right child of tree
{
    TREE -> right = tree_ctor();
    TREE -> right -> prev = TREE;
    TREE -> right -> data = data;
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
    tmp->right = *TREE;
}

void tree_put_exp(p_tree TREE, char* str) //This function convert string into tree
{
    char* ptr = str;
    p_tree tmp;
    int tmp_int = 0;
    int length = strlen(str);
    int i = 0;
    while(i  < length - 1)
    {
        if ((ptr[i] >= '*') && (ptr[i] <= '/'))
        {
            if ((TREE -> prev) && (ptr[i] >= '+') && (ptr[i] <= '-') && ((TREE -> prev -> sign == '*') || (TREE -> prev -> sign == '/')))
            {
                TREE -> prev = TREE->prev -> prev;
                TREE -> prev -> right = NULL;
                TREE -> right = TREE -> prev;
                tmp = TREE -> prev;
                TREE -> prev = TREE;
                TREE = tmp;
            }
            else
            {
                TREE -> data = 0;
                TREE -> sign = ptr[i];
                tree_go_forward(&TREE);
                i++;
            }
        }
        else if ((ptr[i] >= '0') && (ptr[i] <= '9')) //If number then put it into filed "data" of the left child of tree
        {
            i += tree_int_len(ptr + i, &tmp_int);
            tree_put_data_left(TREE, tmp_int);
        }
        else
        {
            printf("This imposible consider");
            exit(1);
        }
    }
}

int tree_culc(p_tree TREE) //This function consider math mathematical expression
{
    if ( TREE -> left && TREE -> right && (TREE -> sign == '+') )
    {
        return (tree_culc(TREE->left) + tree_culc(TREE->right));
    }
    else if ( TREE -> left && TREE -> right && (TREE -> sign == '-') )
    {
        return (tree_culc(TREE -> left) - tree_culc(TREE -> right));
    }
    else if ( TREE -> left && TREE -> right && (TREE -> sign == '*') )
    {
        return (tree_culc(TREE -> left) * tree_culc(TREE -> right));
    }
    else if ( TREE -> left && TREE -> right && (TREE -> sign == '/') )
    {
        return (tree_culc(TREE -> left) / tree_culc(TREE -> right));
    }
    else if ( !(TREE -> left) && !(TREE -> right) )
    {
        return TREE -> data;
    }
    return 0xBAD;
}
