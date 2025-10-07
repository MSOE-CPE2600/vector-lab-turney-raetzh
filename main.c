/**********************
* Name: main.c
* Desc: Main i/o, passes things to and calls on arraymgr
* Auth: Holly Raetz
* Date: Sept 30, 2025
*
* Comp: make clean
**********************/

#include <stdio.h>
#include <string.h>

int main()
{
    char in[30] = "";
    while(strcmp(in,"quit\n"))
    {
        printf("vectcalc> ");
        fgets(in, 30, stdin);
        printf("%s", in);
    }

    printf("Extra changes added!");

    return 0;
}
