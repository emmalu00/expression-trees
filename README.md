# Expression-Trees
## Background
An expression tree is a binary tree used for representing arithmetic expressions. For example, the expression **_3 + ((5+9)*2)_** would yield the following expression tree:

![](https://media.geeksforgeeks.org/wp-content/uploads/expression-tree.png)

Note that leaves are always operands (numbers, in this case), and non-leaf nodes are always operators (+, -, *, /).
We can also write arithmetic expressions in prefix or postfix notation. In prefix notation, operators go BEFORE what they are operating on. In postfix notation, operators go AFTER what they are operating on.

The infix expression 3 + 4 * (12 - 1) can be written as: 
> Prefix: + 3 * 4 – 12 1

> Postfix: 3 4 12 1 - * +

Once we have an expression tree, we can write it in either infix, postfix, or prefix notation by doing an inorder, postorder, or preorder traversal on the tree.

A postorder traversal is done by:

> If the current tree isn’t empty:

> Recursively traverse to the left subtree

> Recursively traverse to the right subtree

> Visit/print the data for the current tree

We can similar to an inorder traversal by putting the “visit/print the data for the current tree” in between the two recursive calls. A preorder traversal can be done by putting the “visit/print the data for the current tree” before the two recursive calls.

## Program Description
This is a program in C that gets a postfix expression from the user along with the user’s choice on whether to convert to prefix or infix. The program then builds an expression tree representing the expression and uses that expression tree to complete the desired conversion. It also prints the evaluation of the original expression (by using the expression tree). _**All of the main logic in the program is done in project4.c**_

## Running the Program
The program compiles through the command line with the following statement: 

`make`

This will produce the executable **_project4.c_**

The program will then run through the command line with the following statement:

`./project4 inputFile`

***
# tree implementation (tree.c)

## typedef struct tnode (TREE)
_TREE_ represents an expression tree. Each _TREE_ can either be a leaf node (which holds a number)or a non-leaf node (which holds an operator).

 
## Methods 

`TREE* create_singleton(int d)`

creates a new singleton (no children) tree to hold an integer data value

`void inorder(TREE* tree, char* buffer)`

does an inorder traversal on the given tree, and writes the traversal in the given buffer

`void preorder(TREE* tree, char* buffer)`

does a preorder traversal on the given tree, and writes the traversal in the given buffer

`typedef void (*trav_fn)(TREE* tree, char* buffer)`

defines a function pointer type called "trav_fn" for a function that takes a tree and character buffer, and that writes a traversal for the tree to the buffer

`int evaluate(TREE* tree)`

returns the evaluation of the expression represented by the given expression tree

`void free_tree(TREE* t)`

releases all the memory allocated for the given tree

*** 
# stack implementation (stack.c)

## Associated Structs

### typedef struct snode (NODE)
_NODE_ represents a node in a stack. The data field is type _TREE_ (defined in tree.h).

### typedef struct STACK
_STACK_ represents a stack of type _TREE_. top is the first _NODE_.

## Methods 

`STACK* init_stack(void)`

init_stack creates and returns a new stack object

`void push(STACK* s, TREE* d)`

adds a value to the top of the given stack

`TREE* pop(STACK* s)`

removes and returns the top value (tree) on the given stack

`void free_stack(STACK* s)`

frees all nodes on stack s
