/* 
 * Author: Emma Lucas
 * 
 * This file implements the functions for a tree.
 */ 

#include "types.h"
#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TREE* create_singleton(int d)
{
    TREE* single = malloc(sizeof(TREE));
    single->data.leafnum = d;
    single->isleaf = true;
    return single;
}

TREE* build_tree(OP oper, TREE* l, TREE* r)
{
    TREE* newTree = malloc(sizeof(TREE));
    newTree->data.operator = oper;
    newTree->left = l;
    newTree->right = r;
    return newTree;
}

void inorder(TREE* tree, char* buffer)
{
    if (tree->isleaf == true)
    {
        char buffer2[100];
        sprintf(buffer2, "%d", tree->data.leafnum);
        strcat(buffer, buffer2);
    }
    else
    {
        strcat(buffer, "(");
        inorder(tree->left, buffer);
        if (tree->data.operator == PLUS)
        {
            strcat(buffer, " + ");
        }
        else if (tree->data.operator == MINUS)
        {
            strcat(buffer, " - ");
        }
        else if (tree->data.operator == TIMES)
        {
            strcat(buffer, " * ");
        }
        else if (tree->data.operator == DIVIDE)
        {
            strcat(buffer, " / ");
        }
        inorder(tree->right, buffer);
        strcat(buffer, ")");
    }
}

void preorder(TREE* tree, char* buffer)
{
    if (tree->isleaf == true)
    {
        char buffer2[100];
        sprintf(buffer2, "%d", tree->data.leafnum);
        strcat(buffer, buffer2);
        strcat(buffer, " ");
    }
    else
    {
        if (tree->data.operator == PLUS)
        {
            strcat(buffer, "+");
        }
        else if (tree->data.operator == MINUS)
        {
            strcat(buffer, "-");
        }
        else if (tree->data.operator == TIMES)
        {
            strcat(buffer, "*");
        }
        else if (tree->data.operator == DIVIDE)
        {
            strcat(buffer, "/");
        }
        strcat(buffer, " ");
        preorder(tree->left, buffer);
        preorder(tree->right, buffer);
    }
}

int evaluate(TREE* tree)
{
    if (tree->isleaf == true)
    {
        return tree->data.leafnum;
    }
    int left = evaluate(tree->left);
    int right = evaluate(tree->right);
    if (tree->data.operator == PLUS)
    {
        return left + right;
    }
    else if (tree->data.operator == MINUS)
    {
        return left - right;
    }
    else if (tree->data.operator == TIMES)
    {
        return left * right;
    }
    else
    {
        return left / right;
    }
}

void free_tree(TREE* t)
{
    if (t->isleaf == true)
    {
        free(t);
    }
    else
    {
        free_tree(t->left);
        free_tree(t->right);
        free(t);
    }
}
