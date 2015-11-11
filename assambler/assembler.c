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

int progtocom(char* st);

int main()
{
    FILE* file_in = fopen("assamly.txt", "r");
    FILE* file_out = fopen("test.txt", "w");
    char* buffer = (char*) calloc (10, sizeof(char));
    int n = 0;
    while(progtocom(buffer) != end_cmd)
    {
    fscanf(file_in, "%s", buffer);
    if (progtocom(buffer) == push_cmd)
    {
        fscanf(file_in, "%d", &n);
        fprintf(file_out, "%d %d ", progtocom(buffer), n);
    }
    else
        fprintf(file_out, "%d ", progtocom(buffer));
    }
    fclose(file_in);
    fclose(file_out);
    free(buffer);
    return 0;
}

int progtocom(char* st)
{
    if(!strcmp(st, "push"))
        return(push_cmd);
    else if(!strcmp(st, "pop"))
        return(pop_cmd);
    else if(!strcmp(st, "add"))
        return(add_cmd);
    else if(!strcmp(st, "sub"))
        return(sub_cmd);
    else if(!strcmp(st, "multi"))
        return(multi_cmd);
    else if(!strcmp(st, "div"))
        return(div_cmd);
    else if(!strcmp(st, "end"))
        return(end_cmd);
}
