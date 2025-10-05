#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // find last node
    Node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(Node **head, int key) {
    Node *temp = *head;
    Node *prev = NULL;

    if (temp == NULL) return;

    // Handle deletion of head (key in head)
    if (temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Find the node to be deleted and its previous node
    while(temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    free(temp);
}

void printList(Node **head) {
    Node *temp = *head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    printList(&head);

    insertAtBeginning(&head, 0);
    printList(&head);

    deleteNode(&head, 2);
    printList(&head);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}