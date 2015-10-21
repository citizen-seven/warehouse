#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char* value;
    int tmp;
    int size;
} stack;

void push(char a,stack* funk);
void pop(stack* funk);

int main()
{
    char* str = (char*) malloc (100 * sizeof(char));
    scanf("%s", str);
    int i = 0;
    stack d;
    stack* funk=&d;
    funk -> value = (char*) malloc (8 * sizeof(char));
    funk -> size = 8;
    funk -> tmp = 0;
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
                if (funk -> value[funk -> tmp - 1] == '(')
                {
                    pop(funk);
                    i++;
                }
                else
                {
                    i++;
                    printf("No");
                    exit(0);
                }
                break;
             case '}':
                if (funk -> value[funk -> tmp - 1] == '{')
                    {
                        pop(funk);
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
                if (funk -> value[funk -> tmp - 1] == '[')
                    {
                        pop(funk);
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
        funk -> value = (char*) realloc(funk, 2 * (funk -> size) * sizeof(char));
        funk -> size = 2 * funk -> size;
    }
    if ((funk -> tmp) < (funk -> size))
    {
        funk -> value[funk -> tmp] = a;
        funk -> tmp++;
    }
}

void pop(stack* funk)
{
    funk -> tmp --;
    if (funk -> tmp < 3 / 8 * funk -> size)
        funk -> value = (char*) realloc(funk, 1 / 2 * sizeof(char));
}
