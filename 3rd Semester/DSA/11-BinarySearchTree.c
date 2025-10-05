#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *insertNode(Node *root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key <= root->data) {
        root->left = insertNode(root->left, key);
    } else {
        root->right = insertNode(root->right, key);
    }
}

void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    /*
        Let's make this tree:
                4
              /   \
             1    5
            / \
           0   3
               /
              2 
    */

    Node *root = createNode(4);
    insertNode(root, 1);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 2);
    insertNode(root, 0);

    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);

    printf("\n\nProgrammed by Milan Bairagi...");
    return 0;
}