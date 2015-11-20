#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef char elem_t;

typedef struct
{
    elem_t* name;
    int data;
    int size;
} stack;

int push(stack* st, elem_t a);
elem_t pop(stack* st);
void stack_resize(stack* st);
void stack_ctor(stack* st, int n);
void stack_dtor(stack* st);
int stack_ok(stack* st);
void stack_dump(stack* st);


#endif // STACK_H_INCLUDED
