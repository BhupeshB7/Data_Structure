//  #include <stdio.h>
//  #include <stdlib.h>
//     typedef struct Node {
//         int data;
//         struct Node* left;
//         struct Node* right;
//     } Node;
//      Node* createNode(int val){
//         Node *newNode = (Node *)malloc(sizeof(Node));
//         newNode->data = data;
//         newNode->left=NULL;
//         newNode->right=NULL;
//         return newNode;
//      }
//      Node* insert(Node* root, int val) {
//         if (root == null) {
//             root = new createNode(val);
//             return root;
//         }
//         if (val < root.data) {
//             root.left = insert(root.left, val);
//         } else {
//             root.right = insert(root.right, val);
//         }
//         return root;
//     }

//     void inOrder(Node* root) {
//         if (root == null) return;
//         inOrder(root.left);
//         printf(root.data + " ");
//         inOrder(root.right);
//     }
//     boolean search(Node* root, int key){
//         if(root == null)return false;
//         if(root.data> key){
//             return search(root.left,key);
//         }else if(root.data==key){
//             return true;
//         }
//         else{
//             return search(root.right,key);
//         }
//     }
// int main(){
//         int values[] = {5, 1, 3, 4, 2, 7};
//         Node* root = NULL;
//         for (int i = 0; i < sizeof(values)/sizeof(values[0]); i++) {
//             root = insert(root, values[i]);
//         }
//             prinf("---------------");
//         inOrder(root);
//             printf("");
//             printf("---------------");
//         if(search(root,27)){
//             printf("Element Found");
//         }else{
//             printf("Element Not Found");
//         }
//     return 0;
// }









#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

int search(Node* root, int key) {
    if (root == NULL) return 0;
    if (root->data > key) {
        return search(root->left, key);
    } else if (root->data == key) {
        return 1;
    } else {
        return search(root->right, key);
    }
}

int main() {
    int values[] = {5, 1, 3, 4, 2, 7};
    Node* root = NULL;
    int i;
    for (i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    printf("---------------\n");
    inOrder(root);
    printf("\n---------------\n");

    if (search(root, 27)) {
        printf("Element Found\n");
    } else {
        printf("Element Not Found\n");
    }

    return 0;
}
