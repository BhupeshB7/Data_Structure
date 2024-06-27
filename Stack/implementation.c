#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int items[MAX];
    int top;
} Stack;
void create_stack(Stack *stack)
{
    stack->top = -1;
}
int isFull(Stack *stack)
{
   return stack->top == MAX - 1;
}
void push_stack(Stack *stack, int item)
{
    if (isFull(stack))
    {
        printf("Stack is full! Can't push  elements %d\n", item);
    }
    else
    {
        stack->items[++stack->top] = item; // Corrected the indexing
        printf("%d pushed onto stack\n", item);
    }
}

int pop_stack(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int item = stack->items[stack->top];
    stack->top--;
    return item;
}
int peek_stack(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}
void display_stack(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty\n");
    }
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
int main()
{
    Stack stack;
    create_stack(&stack);

    push_stack(&stack, 10);
    push_stack(&stack, 20);
    push_stack(&stack, 30);
    push_stack(&stack, 40);
    push_stack(&stack, 50);
    push_stack(&stack, 60);
    push_stack(&stack, 70);
    push_stack(&stack, 80);
    push_stack(&stack, 90);
    push_stack(&stack, 100);
    push_stack(&stack, 110);

    printf("Top element is %d\n", peek_stack(&stack));

    printf("Stack before popping elements:\n");
    display_stack(&stack);

    printf("%d popped from stack\n", pop_stack(&stack));
    printf("%d popped from stack\n", pop_stack(&stack));

    printf("Stack after popping elements:\n");
    display_stack(&stack);

    return 0;
}
