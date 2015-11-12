#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum programmes
{
    end_cmd = 0,
    push_cmd = 1,
    pop_cmd = 2,
    add_cmd = 3,
    sub_cmd = 4,
    multi_cmd = 5,
    div_cmd = 6
};


int main()
{
    FILE* file_in = fopen("test.txt", "r");
    FILE* file_out = fopen("assamly.txt", "w");
    int* buffer = (int*) calloc (1, sizeof(int));
    *buffer = -1;
    int n = 0;
    while(*buffer != end_cmd)
    {
        fscanf(file_in, "%d", buffer);
        if (*buffer == push_cmd)
        {
            fscanf(file_in, "%d", &n);
            fprintf(file_out, "push %d ", n);
        }
        else if (*buffer == pop_cmd)
            fprintf(file_out, "pop ");
        else if (*buffer == add_cmd)
            fprintf(file_out, "add ");
        else if (*buffer == sub_cmd)
            fprintf(file_out, "sub ");
        else if (*buffer == multi_cmd)
            fprintf(file_out, "multi ");
        else if (*buffer == div_cmd)
            fprintf(file_out, "div ");
    }
    fprintf(file_out, "end");
    fclose(file_in);
    fclose(file_out);
    free(buffer);
    return 0;
}


