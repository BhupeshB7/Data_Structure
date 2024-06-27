#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void create_stack(Stack* stack) {
    stack->top = NULL;
}

int is_empty(Stack* stack) {
    return stack->top == NULL;
}

void push_stack(Stack* stack, int item) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation error\n");
        return;
    }
    new_node->data = item;
    new_node->next = stack->top;
    stack->top = new_node;
    printf("%d pushed onto stack\n", item);
}

int pop_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = stack->top;
    int item = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return item;
}  

int peek_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}

void display_stack(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    create_stack(&stack);

    push_stack(&stack, 10);
    push_stack(&stack, 20);
    push_stack(&stack, 30);
    push_stack(&stack, 40);
    push_stack(&stack, 50);

    printf("Top element is %d\n", peek_stack(&stack));

    printf("Stack before popping elements:\n");
    display_stack(&stack);

    printf("%d popped from stack\n", pop_stack(&stack));
    printf("%d popped from stack\n", pop_stack(&stack));

    printf("Stack after popping elements:\n");
    display_stack(&stack);

    return 0;
}
