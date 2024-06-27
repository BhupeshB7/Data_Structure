#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack{
    int size;
    int *array;
};

struct  stack *create_stack();
void push_stack(struct stack *stack, int item);
int pop_stack(struct stack *stack);
int peek_stack(struct stack *stack);
void display_stack(struct stack *stack);
int isEmpty(struct stack *stack);