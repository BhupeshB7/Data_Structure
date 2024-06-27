#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// to create a node using Linkd list
typedef struct node *Node;
 struct node {
	int data;
	 Node next;
};
// define a data structure for the header of the  linked list
typedef struct linked_list *List;
struct linked_list {
    int count;
    Node head;
};
List createNewList();
Node createNewListNode(int value);
void printList(List l1);
void insertFirst(Node N1, List l1);
void insertAtIndex(int index, Node N1, List l1);
void insertLast(Node N1, List l1);
void deleteFirst(List l1);
void deleteAtIndex(int index, List l1);
void deleteLast(List l1);
int searchElement(List l1,int number);