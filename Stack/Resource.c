#include <stdio.h>
#include <stdlib.h>
//#ifndef STACK_H_INCLUDED
//#define STACK_H_INCLUDED

typedef int elem_t;

typedef struct
{
    elem_t* name;
    int data;
    int size;
} stack;

void stack_resize(stack* st)
{
    st -> name =(elem_t*) realloc (st -> name, 2*(st -> size));
    st -> size = 2*st -> size;
}

int stack_ok(stack* st)
{
    return !((st == NULL) || (st -> name == NULL) || (st -> data < 0));
}

int push(stack* st, elem_t a)
{
    if (stack_ok(st))
    {
        if (st -> data < st -> size)
            stack_resize(st);
        st -> name[st -> data] = a;
        st -> data++ ;
        return 0;
    }
    else
    {
        printf("You don`t work with incorrect stack\n");
        return 0;
    }
}

elem_t pop(stack* st)
{
    if (st -> data == 0)
        printf("Underflow stack\n");
    else
        st -> data--;
    return st -> name[st -> data];
}


void stack_ctor(stack* st, int n)
{
    st -> name = (elem_t*) calloc (n, sizeof(elem_t));
    st -> size = n;
}

void stack_dtor(stack* st)
{
    st -> name = NULL;
    free(st -> name);
}

void stack_dump(stack* st)
{
    if (stack_ok(st))
    {
        int i = st -> data;
        for (st -> data -- ; st -> data >= 0 ; (st -> data)--)
            printf("a[%d] = %d\n", st -> data , st -> name[st -> data]);
        st -> data = i;
    }
    else
      printf("You don`t work with incorrect stack\n");
}
