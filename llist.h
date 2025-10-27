/************************************
* Name: llist.c
* Desc: linked list header
* Auth: Holly Raetz
* Date: Oct 14, 2025
************************************/
#include "vector.h"

#ifndef LLIST_H
#define LLIST_H

typedef struct node
{
    vector data;
    struct node* next;
    struct node* prev;
} node;

typedef struct list
{
    node *head;
    node *tail;
} list;

list ll_create();

int ll_size(list *llist);

vector *ll_get(list *llist, char name);

int ll_push_front(list *llist, vector *new_data);
int ll_update_make(list *llist, char name, vector *new_data);

void print_node(list *llist, char name);
void print_list(list *llist);
void fprint_list(list *llist, FILE *file_ptr);
void fget_list(list *llist, FILE *file_ptr);

void ll_clear(list *llist);

#endif