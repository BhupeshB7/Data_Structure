#include "ll.h"

int main(){
    List l1 = createNewList();
   Node n1= createNewListNode(1);
   Node n2= createNewListNode(2);
   Node n3= createNewListNode(3);
   Node n4= createNewListNode(4);
   Node n5= createNewListNode(5);
   Node n6= createNewListNode(6);
   Node n7= createNewListNode(7);
   Node n8= createNewListNode(8);   
   Node n9= createNewListNode(9);   
   Node n10= createNewListNode(10);   
   insertFirst(n1, l1);
   insertFirst(n2, l1);
   insertFirst(n3, l1);   
   insertFirst(n4, l1);
   insertFirst(n5, l1);
   insertFirst(n6, l1);   
   insertFirst(n7, l1);
   insertFirst(n8, l1);
   printList(l1);
   insertLast(n9, l1);
   printList(l1);
   deleteFirst(l1);
   printList(l1);
   deleteLast(l1);
   printList(l1);
//    insertAtIndex(5, n10, l1);
//    printList(l1);
   deleteAtIndex(12, l1);
   deleteAtIndex(2, l1);
   printList(l1);
 int searchNumber =  searchElement(l1,9);
 if(searchNumber==-1){
    printf("Element not found %d",searchNumber);
 }
 else{
    printf("Element found %d ",searchNumber);
 }
}
   