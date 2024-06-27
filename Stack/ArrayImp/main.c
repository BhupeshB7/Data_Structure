#include "sa.h"

int main() {
    struct stack *stack = create_stack();
    push_stack(stack, 10);
    push_stack(stack, 20);
    push_stack(stack, 30);
    push_stack(stack, 40);
    push_stack(stack, 50);

    printf("Top element is %d\n", peek_stack(stack));

    printf("Stack before popping elements:\n");
    display_stack(stack);

    printf("%d popped from stack\n", pop_stack(stack));
    printf("%d popped from stack\n", pop_stack(stack));
    
    display_stack(stack);
}