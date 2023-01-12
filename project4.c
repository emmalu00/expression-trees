/* 
 * Author: Emma Lucas
 * project4.c
 * 
 * This program gets a postfix expression from the user and converts it 
 * to an infix or prefix expression based on the user's preference. The
 * program then uses an expression tree to print an evalaution of the
 * original expression and the conversion of the expression. 
 */ 

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "types.h"
#include "stack.h"
#include "tree.h"

int main()
{
    trav_fn traversals[2] = {inorder, preorder};
    char expression[100];
    printf("Enter postfix expression: ");
    fgets(expression, 100, stdin);
    expression[strcspn(expression, "\n")] = '\0';
    /*//remove spaces
    int nospaces = 0;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] != ' ')
        {
            expression[nospaces] = expression[i];
            nospaces++;
        }
    }
    expression[nospaces] = '\0';
    */
    //construct an expression tree
    STACK* trees = init_stack();
    char* input = strtok(expression, " ");
    //For each piece in our postfix expression
    while (input != NULL)
    {
        if (isdigit(input[0]))
        {
            int num = atoi(input);
            TREE* single = create_singleton(num);
            push(trees, single);
        }
        else
        {
            TREE* tree1 = pop(trees);
            TREE* tree2 = pop(trees);
            TREE* newTree = NULL;
            if (strcmp(input, "+") == 0)
            {
                newTree = build_tree(PLUS, tree2, tree1);
            }
            else if (strcmp(input, "-") == 0)
            {
                newTree = build_tree(MINUS, tree2, tree1);
            }
            else if (strcmp(input, "*") == 0)
            {
                newTree = build_tree(TIMES, tree2, tree1);
            }
            else if (strcmp(input, "/") == 0)
            {
                newTree = build_tree(DIVIDE, tree2, tree1);
            }
            push(trees, newTree);
        }
        input = strtok(NULL, " ");

    }
    TREE* final = pop(trees);
    char output[100] = "";
    int response = 0;
    printf("Enter 1 for infix, 2 for prefix: ");
    scanf("%d", &response);
    traversals[response - 1](final, output);
    int result = evaluate(final);
    printf("%s\nAnswer: %d\n", output, result);
    free_stack(trees);
    
}