#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP 1
#define MIN_HEAP 0

typedef struct {
    int *data;
    int size;
    int capacity;
    int heap_type; // MAX_HEAP or MIN_HEAP
} PriorityQueue;

PriorityQueue* create_priority_queue(int capacity, int heap_type) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (int*)malloc(sizeof(int) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    pq->heap_type = heap_type;
    return pq;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(PriorityQueue *pq, int index) {
    int parent_index = (index - 1) / 2;
    if (index && ((pq->heap_type == MAX_HEAP && pq->data[index] > pq->data[parent_index]) ||
                  (pq->heap_type == MIN_HEAP && pq->data[index] < pq->data[parent_index]))) {
        swap(&pq->data[index], &pq->data[parent_index]);
        heapify_up(pq, parent_index);
    }
}

void heapify_down(PriorityQueue *pq, int index) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int selected_child_index = index;

    if (left_child_index < pq->size && 
        ((pq->heap_type == MAX_HEAP && pq->data[left_child_index] > pq->data[selected_child_index]) ||
         (pq->heap_type == MIN_HEAP && pq->data[left_child_index] < pq->data[selected_child_index]))) {
        selected_child_index = left_child_index;
    }

    if (right_child_index < pq->size && 
        ((pq->heap_type == MAX_HEAP && pq->data[right_child_index] > pq->data[selected_child_index]) ||
         (pq->heap_type == MIN_HEAP && pq->data[right_child_index] < pq->data[selected_child_index]))) {
        selected_child_index = right_child_index;
    }

    if (selected_child_index != index) {
        swap(&pq->data[index], &pq->data[selected_child_index]);
        heapify_down(pq, selected_child_index);
    }
}

void push(PriorityQueue *pq, int value) {
    if (pq->size == pq->capacity) {
        pq->capacity *= 2;
        pq->data = (int*)realloc(pq->data, pq->capacity * sizeof(int));
    }
    pq->data[pq->size++] = value;
    heapify_up(pq, pq->size - 1);
}

int top(PriorityQueue *pq) {
    if (pq->size) {
        return pq->data[0];
    }
    return -1; // or some other error value
}

void pop(PriorityQueue *pq) {
    if (pq->size) {
        pq->data[0] = pq->data[--pq->size];
        heapify_down(pq, 0);
    }
}

int main() {
    PriorityQueue *pq = create_priority_queue(10, MAX_HEAP);
    
    push(pq, 10);
    push(pq, 80);
    push(pq, 30);
    push(pq, 90);
    push(pq, 20);
    
    printf("size of pq %d\n", pq->size);
    while (pq->size) {
        printf("%d ", top(pq));
        pop(pq);
    }
    printf("\n");
    
    PriorityQueue *pq2 = create_priority_queue(10, MIN_HEAP);
    push(pq2, 10);
    push(pq2, 80);
    push(pq2, 30);
    push(pq2, 90);
    push(pq2, 20);
    
    printf("size of pq2 %d\n", pq2->size);
    while (pq2->size) {
        printf("%d ", top(pq2));
        pop(pq2);
    }
    printf("\n");

    // Free the allocated memory
    free(pq->data);
    free(pq);
    free(pq2->data);
    free(pq2);

    return 0;
}
