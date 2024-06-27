#include "ll.h"

List createNewList() {
    List newList ;
    newList = (List)malloc(sizeof(struct linked_list));
    newList->count = 0;
    newList->head = NULL;
    return newList;
}

Node createNewListNode(int value) {
    Node newNode;
    newNode = (Node)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertFirst(Node N1, List l1) {
    if(l1->head==NULL) {
        l1->head = N1;
        N1->next = NULL;
        l1->count++;
    }
    else{
        Node temp = l1->head;
        l1->head = N1;
        N1->next = temp;
        l1->count++;
    }
}
void insertLast(Node N1,List l1){
    if(l1->head==NULL){
        l1->head = N1;
        N1->next = NULL;
        l1->count++;
    }
    else{
        Node temp=l1->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=N1;
        N1->next=NULL;
        l1->count++;
    }
}
void insertAtIndex(int index,Node N1,List l1){
    if(l1->head==NULL){
        printf("List is empty");
        return;
    }
    else{
        Node temp=l1->head;
        int i=0;
        while(i<index-1){
            temp=temp->next;
            i++;
        }
        N1->next=temp->next;
        temp->next=N1;
        l1->count++;
    }
}
void deleteFirst(List l1){
    if(l1->head==NULL){
        printf("List is empty");
        return;
    }
    else{
        Node temp=l1->head;
        l1->head=l1->head->next;
        free(temp);
        l1->count--;
    }
    return;
}
void deleteLast(List l1){
    if(l1->head==NULL){
        printf("List is empty");
        return;
    }
    if (l1->head->next == NULL) {
        free(l1->head);
        l1->head = NULL;
        l1->count = 0;
    } 
    else{
        Node temp=l1->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        free(temp->next);
        l1->count--;
    }
}
void deleteAtIndex(int index, List l1) {
    if (l1->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        Node temp = l1->head;
        l1->head = l1->head->next;
        free(temp);
        l1->count--;
        return;
    }

    Node temp = l1->head;
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Index out of bounds\n");
        return;
    }

    Node nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    l1->count--;
}

void printList(List l1){
    Node temp = l1->head;
    printf("\tHEAD\n");
    printf("\t|\n");
    printf("\t");
    while(temp!=NULL){
        printf("%d ->  ",temp->data);
        temp = temp->next;
    }
    printf("[NULL]");
    printf(" %d",l1->count);
    printf("\n");
}
int searchElement(List l1,int number){
    if(l1->head==NULL){
        printf("Empty list");
        return -1;
    }
    else{
        Node temp = l1->head;
        while(temp!=NULL){
            if(temp->data==number){
                return temp->data;
            }
            temp=temp->next;
        }
    }
    return -1;
}