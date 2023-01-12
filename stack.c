/* 
 * Author: Emma Lucas
 * 
 * This file implements the functions for a stack.
 */ 

#include "types.h"
#include "tree.h"
#include "stack.h"
#include <stdlib.h>

STACK* init_stack(void)
{
    STACK* newStack = malloc(sizeof(STACK));
    return newStack;
}

void push(STACK* s, TREE* d)
{
    NODE* newnode = malloc(sizeof(NODE));
    newnode->next = s->top;
    newnode->data = d;
    s->top = newnode;
}

TREE* pop(STACK* s)
{
    TREE* val = s->top->data;
    s->top = s->top->next;
    return val;
}

void free_stack(STACK* s)
{
    while (s->top != NULL)
    {
        free(s->top->data);
        s->top = s->top->next;
    }
    free(s);
}


