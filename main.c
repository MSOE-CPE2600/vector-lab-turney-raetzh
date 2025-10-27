/**********************
* Name: main.c
* Desc: Main i/o, passes things to parser
* Auth: Holly Raetz
* Date: Sept 30, 2025
*
* Comp: make clean
**********************/

#include <stdio.h>
#include <string.h>
#include "listmgr.h"
#include "parser.h"
#include "llist.h"

int main()
{
    list vectors = ll_create();

    FILE *file_ptr;

    char in[50];
    int quit = 0;

    char *file_name;

    while(quit == 0)
    {
        printf("vectcalc> ");
        fgets(in, 30, stdin);

        if(strcmp(in, "quit\n") == 0)
        {
            quit = 1;
        } else if(!strncmp(in, "load", 4))
        {
            file_name = strtok(in, " \n");
            file_name = strtok(NULL, " \n"); //2 strtoks to get rid of "load"
            strcat(file_name, ".csv");
            file_ptr = fopen(file_name, "r");
            if(file_ptr)
            {
                fget_list(&vectors, file_ptr);
                fclose(file_ptr);
            } else
            {
                printf("Error accessing file %s.\n", file_name);
            }
        } else if(!strncmp(in, "save", 4))
        {
            file_name = strtok(in, " \n");
            file_name = strtok(NULL, " \n"); //2 strtoks to get rid of "save"
            strcat(file_name, ".csv");
            file_ptr = fopen(file_name, "w");
            if(file_ptr)
            {
                fprint_list(&vectors, file_ptr);
                printf("Saved data to file %s.\n", file_name);
                fclose(file_ptr);
            } else
            {
                printf("Error accessing file %s.\n", file_name);
            }
        } else
        {
            parse(in, &vectors);
        }
    }
    ll_clear(&vectors);

    return 0;
}