#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char* value;
    int tmp;
    int size;
} stack;

void push(char a,stack* funk);
int pop(stack* funk);

/*
1) Should be check in POP before you decrement tmp. It causes errors, for example on sequence: ))
2) you have i++ exañåly in every one of switch cases. why not take it out of switch?
3) There is a default case in switch, which will definitely help you with errors. (like number in you sequence)
4) see comments below
*/

int main()
{
    char* str = (char*) malloc (100 * sizeof(char));
    scanf("%s", str);
    int i = 0;
    stack d;
    stack* funk=&d;
    d.value = (char*) malloc (8 * sizeof(char));
    funk -> size = 8;  // what is the reason for this? you can use d.value, and d.tmp.
    funk -> tmp = 0;   // why create new variable?
    while(str[i] != '\0')
    {
        switch(str[i])
        {
             case '(':
                {
                    push(str[i], funk);
                    i++;
                    break;
                }
             case '{':
                {
                    push(str[i], funk);
                    i++;
                    break;
                }
             case '[':
                {
                    push(str[i], funk);
                    i++;
                    break;
                }
             case ')':
                if (pop(funk) == '(')
                {
                    i++;
                }
                else
                {
                    i++; // what's that for?
                    printf("No"); // again, maybe smth like "Incorrect"?
                    exit(0);
                }
                break;
             case '}':
                if (pop(funk) == '{')
                    {
                        i++;
                    }
                    else
                    {
                        i++;
                        printf("No");
                        exit(0);
                    }
                    break;
             case ']':
                if (pop(funk) == '[')
                    {
                        i++;
                    }
                    else
                    {
                        i++;
                        printf("No");
                        exit(0);
                    }
                    break;
        }
    }
    if (funk -> tmp != 0)
        printf("No");
    else
        printf("Yes");
    free(str);
    free(funk -> value);
    return 0;

}

void push(char a, stack* funk)
{
    if ((funk -> tmp) >= (funk -> size))
    {
        funk -> value = (char*) realloc(funk->value, 2 * (funk -> size) * sizeof(char));
        funk -> size = 2 * funk -> size;
    }
    if ((funk -> tmp) < (funk -> size))
    {
        funk -> value[funk -> tmp] = a;
        funk -> tmp++;
    }
}

int pop(stack* funk)
{
    // here should be check
    funk -> tmp --;
    if (funk -> tmp < 3 / 8 * funk -> size )
       funk -> value = (char*) realloc(funk->value, 1 / 2 * (funk -> size) * sizeof(char));
    // you have changed the size, but not the size variable!!
    return funk -> value[funk -> tmp];
}
