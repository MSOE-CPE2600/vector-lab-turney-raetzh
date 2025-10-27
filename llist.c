/************************************
* Name: llist.c
* Desc: linked list implementation for vector lab
* Auth: Holly Raetz
* Date: Oct 14, 2025
************************************/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "llist.h"
#include "vector.h"

list ll_create(void)
{
    list to_return = {NULL, NULL};
    return to_return;
}

int ll_size(list *llist)
{
    int size = 0;
    node *iterator = llist->head;
    while(iterator)
    {
        size++;
        iterator = iterator->next;
    }
    return size;
}

static node *make_node(vector *new_data)
{
    node *new_node = (node *)malloc(sizeof(node));

    new_node->data = *new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

static void deallocate(node *rm_node)
{
    free(rm_node);
    return;
}

node *ll_search(list *llist, char name)
{
    node *iterator = llist->head;
    while(iterator)
    {
        if(iterator->data.name == name)
        {
            return iterator;
        }
        iterator = iterator->next;
    }
    return NULL;
}

vector *ll_get(list *llist, char name)
{
    node *vector_at = ll_search(llist, name);
    return &(vector_at->data);
}



int ll_push_front(list *llist, vector *new_data)
{
    if(new_data)
    {
        node *new_node = make_node(new_data);

        if(llist->head == NULL)
        {
            llist->head = new_node;
        } else
        {
            new_node->next = llist->head;
            llist->head->prev = new_node;
            llist->head = new_node;
        }
        return 0;
    }
    return 1;
}

int ll_remove(list *llist, node *rm_node)
{
    if(rm_node)
    {
        if(rm_node->next)
        {
            rm_node->next->prev = rm_node->prev;
        } else
        {
            llist->tail = rm_node->prev;
        }

        if(rm_node->prev)
        {
            rm_node->prev->next = rm_node->next;
        } else
        {
            llist->head = rm_node->next;
        }
        deallocate(rm_node);
        return 0;
    }
    return 1;
}



int ll_update_make(list *llist, char name, vector *new_data) {
    new_data->name = name;
    node *update = ll_search(llist, name);
    if(update)
    {
        update->data = *new_data;
        return 0;
    } else
    {
        return ll_push_front(llist, new_data);
    }
    return 1;
}

void print_node(list *llist, char name)
{
    node *to_print = ll_search(llist, name);
    if(to_print)
    {
        printf("%3c %3.3f %3.3f %3.3f\n", to_print->data.name, to_print->data.x, to_print->data.y, to_print->data.z);
    }
    return;
}

void print_list(list *llist)
{
    node *iterator = llist->head;
    while(iterator)
    {
        printf("%3c %3.3f %3.3f %3.3f\n", iterator->data.name, iterator->data.x, iterator->data.y, iterator->data.z);
        iterator = iterator->next;
    }
    return;
}

void fprint_list(list *llist, FILE *file_ptr)
{
    node *iterator = llist->head;
    while(iterator)
    {
        fprintf(file_ptr, "%c,%3.3f,%3.3f,%3.3f\n", iterator->data.name, iterator->data.x, iterator->data.y, iterator->data.z);
        iterator = iterator->next;
    }
    return;
}

void fget_list(list *llist, FILE *file_ptr)
{
    char line[50];
    ll_clear(llist);
    while(fgets(line, 50, file_ptr))
    {
        vector v;
        char *token;
        token = strtok(line, ",\n");
        v.name = token[0];
        token = strtok(NULL, ",\n");
        if(isdigit(token[0]))
        {
            v.x = atof(token);
        } else {
            printf("Error reading file.\n");
            return;
        }
        token = strtok(NULL, ",");
        if(isdigit(token[0]))
        {
            v.y = atof(token);
        } else {
            printf("Error reading file.\n");
            return;
        }
        token = strtok(NULL, ",");
        if(isdigit(token[0]))
        {
            v.z = atof(token);
        } else {
            printf("Error reading file.\n");
            return;
        }
        ll_update_make(llist, v.name, &v);
    }

    printf("Loaded data in file.\n");
    return;
}

void ll_clear(list *llist)
{
    while(!ll_remove(llist, llist->head))
    {

    }
    return;
}