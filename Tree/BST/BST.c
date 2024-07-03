#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Node *insert(Node *root, int val)
{
    if (root == NULL)
    {
        root = createNode(val);
        return root;
    }
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}
int search(Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data > key)
    {
        return search(root->left, key);
    }
    else if (root->data == key)
    {
        return 1;
    }
    else
    {
        return search(root->right, key);
    }
}
Node *inOrderSuccessor(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}
Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);

    else if (val > root->data)
        root->right = deleteNode(root->right, val);

    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
        // Case 2: One child (left)
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: Two children
        else
        {
            Node *temp = inOrderSuccessor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    int values[] = {5, 1, 3, 4, 2, 7};
    Node *root = NULL;
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
    {
        root = insert(root, values[i]);
    }
    printf("---------------\n");
    inOrder(root);
    printf("\n");
    deleteNode(root, 3);
    printf("In-Order traversal after deletion:\n");
    inOrder(root);
    printf("\n");
    printf("---------------\n");
    if (search(root, 27))
    {
        printf("Element Found\n");
    }
    else
    {
        printf("Element Not Found\n");
    }

    return 0;
}