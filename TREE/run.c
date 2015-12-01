#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main()
{
    p_tree test = tree_ctor();
    p_tree tmp = test;
    char str[100];
    scanf("%s", str);
    printf("%s = ", str);
    tree_put_exp(tmp, str);
    printf("%d", tree_culc(test));
    //tree_dtor(test);
    return 0;
}
