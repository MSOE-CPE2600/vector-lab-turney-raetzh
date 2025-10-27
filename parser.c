/**********************
* Name: parser.c
* Desc: parses input and interacts with llist
* Auth: Holly Raetz
* Date: Sept 30, 2025
**********************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "llist.h"
#include "listmgr.h"

void parse(char *in, list *vectors) {
    char *zero = "0";

    char *token[6];
    for(int i = 0; i < 6; i++)
    {
        token[i] = NULL;
    }

    int length = 0;

    token[length] = strtok(in, " \n");
    while(token[length] != NULL && length < 5)
    {
        length++;
        token[length] = strtok(NULL, ", \n");
    }

    switch(length)
    {
        case 1:
            if(strcmp(token[0], "-h") == 0 || strcmp(token[0], "help") == 0)
            {
                printf("Vector Calculator V2 Help\na - prints vector a\na = 1 2 3 - sets values of a\na + b - prints result of a + b\n    valid operations: +, -, * (scalar mult), . (dot), x (cross)\nc = a + b - sets c to result of a + b\n*note: when including decimals less than 1 please include the 0 prior to decimal point! :)\nload: loads file with whatever name you input afterwards. Assumes .csv\nsave: saves file with whatever name you input afterwards. Assumes .csv\n");
            } else if(strcmp(token[0], "list") == 0)
            {
                print_list(vectors);
            } else if(strcmp(token[0], "clear") == 0)
            {
                ll_clear(vectors);
                printf("Cleared vectors.\n");
            } else
            {
                print_node(vectors, token[0][0]);
            }
            break;
        case 2:
            if(token[1][0] == '=')
            {
                assign(vectors, token[0][0], zero, zero, zero);
            }
            break;
        case 3:
            switch(token[1][0])
            {
                case '+':
                    addres(vectors, token[0][0], token[2][0], ' ');
                    break;
                case '-':
                    subtractres(vectors, token[0][0], token[2][0], ' ');
                    break;
                case '*':
                    if(isdigit(token[2][0]))
                    {
                        float scalar = atof(token[2]);
                        multres(vectors, scalar, token[0][0], ' ');
                    } else if(isdigit(token[0][0]))
                    {
                        float scalar = atof(token[0]);
                        multres(vectors, scalar, token[2][0], ' ');
                    } else
                    {
                        printf("Invalid arguments.\n");
                    }
                    break;
                case '.':
                    dotres(vectors, token[0][0], token[2][0]);
                    break;
                case 'x':
                    crossres(vectors, token[0][0], token[2][0], ' ');
                    break;
                case '=':
                    assign(vectors, token[0][0], token[2], zero, zero);
                    break;
                default:
                    printf("Invalid operator.\n");
            }
            break;
        case 4:
            if(token[1][0] == '=')
            {
                assign(vectors, token[0][0], token[2], token[3], zero);
            }
            break;
        case 5:
            switch(token[3][0])
            {
                case '+':
                    addres(vectors, token[2][0], token[4][0], token[0][0]);
                    break;
                case '-':
                    subtractres(vectors, token[2][0], token[4][0], token[0][0]);
                    break;
                case '*':
                    if(isdigit(token[2][0]))
                    {
                        float scalar = atof(token[2]);
                        multres(vectors, scalar, token[4][0], token[0][0]);
                    } else if(isdigit(token[4][0]))
                    {
                        float scalar = atof(token[4]);
                        multres(vectors, scalar, token[2][0], token[0][0]);
                    } else
                    {
                        printf("Invalid arguments.\n");
                    }

                    break;
                case '.':
                    dotres(vectors, token[2][0], token[4][0]);
                    break;
                case 'x':
                    crossres(vectors, token[2][0], token[4][0], token[0][0]);
                    break;
                default:
                    if(token[1][0] == '=')
                    {
                        assign(vectors, token[0][0], token[2], token[3], token[4]);
                    } else
                    {
                        printf("Invalid operator.\n");
                    }
            }
            break;
        default:
            printf("Command not recognized.\n");
    }
}