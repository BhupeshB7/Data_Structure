#include "sa.h"
#define MAX_SIZE 10
struct stack* create_stack(){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size=0;
    s->array= (int*)malloc(sizeof(int)*MAX_SIZE);
    return s;
}
int isEmpty(struct stack* s){
    return s->size==0;
}
void push_stack (struct stack* s,int data){
    if(s->size==MAX_SIZE){
        printf("Stack Overflow");
        return;
    }
    s->array[s->size]=data;
    s->size++;
}
int pop_stack(struct stack* s){
    isEmpty(s);
    int data=s->array[s->size-1];
    s->size--;
    return data;
}
int peek_stack(struct stack* s){
    isEmpty(s);
    return s->array[s->size-1];
}
void display_stack(struct stack* s){
    for(int i=0;i<s->size;i++){
        printf("| %d |",s->array[i]);
    }
    printf("\n");
}