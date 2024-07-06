#include <stdio.h>
#include <stdlib.h>

typedef struct node *Node;
typedef struct linked_list *List;

struct node
{
    int data;
    Node next;
};

struct linked_list
{
    int count;
    Node head;
};
List createNewList()
{
    List newList;
    newList = (List)malloc(sizeof(struct linked_list));
    newList->count = 0;
    newList->head = NULL;
    return newList;
}
Node createNewListNode(int value)
{
    Node newNode;
    newNode = (Node)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insertFirst(Node N1, List l1)
{
    if (l1->head == NULL)
    {
        l1->head = N1;
        N1->next = NULL;
        l1->count++;
    }
    else
    {
        Node temp = l1->head;
        l1->head = N1;
        N1->next = temp;
        l1->count++;
    }
}

void insertAtPosition(int index, Node N1, List l1)
{
    if (l1->head == NULL)
    {
        printf("Node is Empty");
        return;
    }
    else
    {
        Node temp = l1->head;
        int i = 0;
        while (i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        N1->next = temp->next;
        temp->next = N1;
        l1->count++;
    }
}
void insertAtLast(Node N1, List l1)
{
    if (l1->head == NULL)
    {
        l1->head = N1;
        N1->next = NULL;
        l1->count++;
    }
    else
    {
        Node temp = l1->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = N1;
        N1->next = NULL;
        l1->count++;
    }
}

void printList(List l1)
{
    Node temp = l1->head;
    while (temp != NULL)
    {
        printf("%d ->  ", temp->data);
        temp = temp->next;
    }
    printf("[NULL]\n");
    printf("Total number of nodes: %d\n", l1->count);
    printf("\n");
}

int searchElement(List l1, int num)
{
    Node temp = l1->head;
    while(temp->next!=NULL){
        if(temp->data==num){
            return temp->data;
        }
        temp=temp->next;
    }
    return -1;
}
int main()
{
    List l1 = createNewList();
    Node n1 = createNewListNode(10);
    Node n2 = createNewListNode(20);
    Node n3 = createNewListNode(30);
    Node n4 = createNewListNode(40);
    Node n5 = createNewListNode(50);
    Node n6 = createNewListNode(70);
    Node n7 = createNewListNode(80);
    insertFirst(n1, l1);
    insertFirst(n2, l1);
    insertFirst(n3, l1);
    insertFirst(n4, l1);
    insertFirst(n5, l1);
    printList(l1);
    insertAtPosition(2, n6, l1);
    insertAtLast(n7, l1);
    printList(l1);
    printf("\n");
    int num =searchElement(l1, 20);
    if(num ==-1){
        printf("%d not found in the List", num);
    }else{
        printf("%d found in the list",num);
    }
}