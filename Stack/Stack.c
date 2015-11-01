#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    stack stack_test;
    stack_ctor(&stack_test, 8);
    push(&stack_test, 1);
    push(&stack_test, 2);
    push(&stack_test, 3);
    push(&stack_test, 4);
    push(&stack_test, 5);
    push(&stack_test, 6);
    push(&stack_test, 7);
    push(&stack_test, 8);
    if (stack_ok(&stack_test))
        printf("Stack is correct\n");
    else
        printf("Stack is incorrect\n");
    stack_dump(&stack_test);

    pop(&stack_test);
    pop(&stack_test);
    pop(&stack_test);
    pop(&stack_test);
    stack_dump(&stack_test);
    stack_dtor(&stack_test);
    if (stack_ok(&stack_test))
        printf("Stack is correct\n");
    else
        printf("Stack is incorrect\n");
    push(&stack_test, 1);
    stack_dump(&stack_test);
    return 0;
}
