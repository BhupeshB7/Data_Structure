#include <stdio.h>
#include <stdlib.h>

// Define the structure for the nodes of the binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the binary tree
Node* buildTree(int nodes[], int* idx, int size) {
    if (*idx >= size || nodes[*idx] == -1) return NULL;
    Node* root = createNode(nodes[*idx]);
    (*idx)++;
    root->left = buildTree(nodes, idx, size);
    (*idx)++;
    root->right = buildTree(nodes, idx, size);
    return root;
}

// Preorder traversal
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder traversal
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Level order traversal
void levelOrder(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    queue[rear++] = NULL; // Add NULL as a marker for the end of the first level

    while (front < rear) {
        Node* temp = queue[front++];

        if (temp != NULL) {
            printf("%d ", temp->data);
            if (temp->left != NULL) queue[rear++] = temp->left;
            if (temp->right != NULL) queue[rear++] = temp->right;
        } else {
            // End of current level
            printf("\n");
            if (front < rear) {
                queue[rear++] = NULL; // Add marker for next level
            }
        }
    }
}

// Main function to test the tree
int main() {
    int nodes[] = {1, 2, 4, 8, -1, -1, 9, -1, -1, 5, 10, -1, -1, 11, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int size = sizeof(nodes) / sizeof(nodes[0]);
    int idx = 0;

    Node* root = buildTree(nodes, &idx, size);

    printf("Root data %d\n", root->data);

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Level Order traversal:\n");
    levelOrder(root);

    return 0;
}
