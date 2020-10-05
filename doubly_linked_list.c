//
// Created by kkuli on 18.06.2020.
//
#include <vcruntime.h>
#include <stdio.h>
#include "doubly_linked_list.h"
#include <stdlib.h>

struct doubly_linked_list_t* dll_create()
{
    struct doubly_linked_list_t* lista = (struct doubly_linked_list_t*)calloc(1, sizeof(struct doubly_linked_list_t));
    if(lista == NULL)
    {
        return NULL;
    }
   return lista;

}

int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
    if(dll == NULL)
    {
        return 1;
    }
    struct node_t* node = (struct node_t*)calloc(1,sizeof(struct node_t));
    if(node == NULL)
    {
        return 2;
    }
    node->data = value;
    if(dll->head == NULL)
    {
        dll->head = dll->tail = node;
        return 0;
    }
    struct node_t* pomoc = dll->head;
    while(pomoc->next)
    {
        pomoc = pomoc->next;
    }
    node->prev = pomoc;
    pomoc->next = node;
    dll->tail = node;
    return 0;
}

int dll_push_front(struct doubly_linked_list_t* dll, int value)
{ if(dll == NULL)
    {
        return 1;
    }
    struct node_t* node = (struct node_t*)calloc(1,sizeof(struct node_t));
    if(node == NULL)
    {
        return 2;
    }
    node->data = value;
    if(!dll->head )
    {
        dll->head = node;
        dll->tail = node;
        return 0;
    }
    node->prev = NULL;
    node->next = dll->head;
    dll->head = node;
   // node->next->prev = node;
    return 0;
}


int dll_pop_front(struct doubly_linked_list_t* dll, int* err_code)
{
    if(dll == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(dll->head == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    struct node_t* node = dll->head;
    int val = dll->head->data;
    if(node->next != NULL) {
        node->next->prev = NULL;
    } else
        dll->tail = NULL;
    dll->head = node->next;
    free(node);
    if(err_code != NULL)
        *err_code = 0;
    return val;

}
int dll_pop_back(struct doubly_linked_list_t* dll, int* err_code)
{
    if(dll == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(dll->head == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }

    struct node_t* node = dll->head;
    struct node_t* prenode = NULL;

    while(node->next)
    {
        prenode = node;
        node = node->next;
    }

    int val = node->data;
    if(prenode)
        prenode->next = NULL;
    else dll->head = NULL;
    dll->tail = prenode;
    free(node);
    if(err_code != NULL)
        *err_code = 0;
    return val;

}

int dll_back(const struct doubly_linked_list_t* dll, int* err_code)
{
    if(dll == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(dll->head == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    struct node_t* node = dll->head;
    while(node->next)
    {
        node = node->next;
    }
    int val = node->data;
    if(err_code != NULL)
        *err_code = 0;
    return val;

}
int dll_front(const struct doubly_linked_list_t* dll, int* err_code)
{
    if(dll == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(dll->head == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    return dll->head->data;
}

struct node_t* dll_begin(struct doubly_linked_list_t* dll)
{
    if(dll == NULL)
        return NULL;
    return dll->head;
}
struct node_t* dll_end(struct doubly_linked_list_t* dll)
{
    if(dll == NULL)
    {

        return NULL;
    }
    if(dll->head == NULL)
    {
        return NULL;
    }
    struct node_t* node = dll->head;
    while(node->next)
    {
        node = node->next;
    }
    return node;
}

int dll_size(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL)
    {

        return -1;
    }
    if(dll->head == NULL)
    {
        return 0;
    }
    struct node_t* node = dll->head;
    int counter = 0;
    while(node)
    {
        node = node->next;
        counter++;
    }
    return counter;
}
int dll_is_empty(const struct doubly_linked_list_t* dll)
{
    if (dll == NULL)
    {
        return -1;
    }
    if (dll->head == NULL)
    {
        return 1;
    }
    return 0;

}

int dll_at(const struct doubly_linked_list_t* dll, unsigned int index, int* err_code)
{
    if(dll == NULL || (int)index < 0 || (int)index > dll_size(dll) )
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    struct node_t* node = dll->head;
    int i = 0;
    for(i = 0; i < (int)index ; i++)
    {
        if(node == NULL)
        {
            break;
        }
        node = node->next;
    }
    if(node == NULL || i != (int)index ) {
        if (err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(err_code != NULL)
        *err_code = 0;
    return node->data;
}

int dll_insert(struct doubly_linked_list_t* dll, unsigned int index, int value)
{
    if(dll == NULL || (int)index < 0 || (int)index > dll_size(dll) )
        return 1;
    if((int)index == 0)
    {
        return dll_push_front(dll,value);
    }
    if((int)index == dll_size(dll))
    {
        return dll_push_back(dll,value);
    }
    struct node_t* node_to_add = ( struct node_t* )malloc(sizeof( struct node_t));
    node_to_add->data = value;
    struct node_t* node = dll->head;
    struct node_t* prenode = NULL;
    for(int i = 0; i < (int)index ; i++)
    {
        if(node == NULL)
            break;
        prenode = node;
        node = node->next;
    }
    prenode->next = node_to_add;
    node_to_add->prev = prenode;
    node->prev = node_to_add;
    node_to_add->next = node;
    return 0;
}
int dll_remove(struct doubly_linked_list_t* dll, unsigned int index, int* err_code)
{
    if(dll == NULL || (int)index < 0 || (int)index > dll_size(dll) )
        return 1;
    if((int)index == 0)
    {
        return dll_pop_front(dll,err_code);
    }
    if((int)index == dll_size(dll))
    {
        return dll_pop_back(dll,err_code);
    }
    struct node_t* node = dll->head;
    struct node_t* prenode = NULL;
    for(int i = 0; i < (int)index ; i++)
    {
        if(node == NULL)
            break;
        prenode = node;
        node = node->next;
    }
    prenode->next = node->next;
    node->next->prev = prenode;
    int val = node->data;
    free(node);
    node = NULL;
    return val;

}

void dll_clear(struct doubly_linked_list_t* dll)
{
    if(dll == NULL|| dll->head == NULL || dll->tail == NULL)
        return ;
    struct node_t* node = dll->head;
    while(node)
    {
        dll->head = dll->head->next;
        free(node);
        node = dll ->head;
    }
    dll->tail = NULL;
}

void dll_display(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL|| dll->head == NULL || dll->tail == NULL)
        return ;
    struct node_t* node = dll->head;
    while(node)
    {
        printf("%d ",node->data);
        node = node->next;
    }
}
void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
    if(dll == NULL|| dll->head == NULL || dll->tail == NULL)
        return ;
    struct node_t* node = dll->tail;
    while(node)
    {
        printf("%d ",node->data);
        node = node->prev;
    }
}

