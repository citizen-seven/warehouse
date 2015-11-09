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

/*
1) Firstly. I couldn't run the program. I mean Stack.c. Like at all. Even compilation caused me troubles...
2) See my comments below
*/

void stack_resize(stack* st)
{
    st -> name =(elem_t*) realloc (st -> name, 2*(st -> size));
    st -> size = 2*st -> size; // it is better to put this line before
}

int stack_ok(stack* st)
{
    return !((st == NULL) || (st -> name == NULL) || (st -> data < 0));
}

int push(stack* st, elem_t a)
{
    if (stack_ok(st))
    {
        if (st -> data < st -> size) // is is always true
            stack_resize(st); // you always resize???
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
    // where is initialization for st->data?
}

void stack_dtor(stack* st)
{
    st -> name = NULL;
    free(st -> name); // free(NULL)!!
}

void stack_dump(stack* st)
{
    if (stack_ok(st))
    {
        int i = st -> data;
        for (st -> data -- ; st -> data >= 0 ; (st -> data)--) 
          //decrementing data twice? or what is the first argument of cycle?
            printf("a[%d] = %d\n", st -> data , st -> name[st -> data]);
        st -> data = i;
    }
    else
      printf("You don`t work with incorrect stack\n");
}
