#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);

    newNode->next = *head;
    (*head)->prev = newNode;

    *head = newNode;
}

void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);

    // Assign new node as a head if head is null
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Find last node
    Node *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    newNode->prev = lastNode;
    lastNode->next = newNode;
}

void deleteNode(Node **head, int key) {
    Node *curr = *head;

    // find current node
    while(curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    if (curr == NULL) return;

    Node *prev = curr->prev;
    Node *next = curr->next;

    // Change head to second node if head is supposed to be deleted
    if (prev == NULL) *head = curr->next;

    if (prev != NULL) prev->next = curr->next;
    if (next != NULL) next->prev = curr->prev;
    free(curr);
}

void printList(Node **head) {
    Node *temp = *head;

    printf("NULL <==> ");
    while(temp != NULL) {
        printf("%d <==> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printList(&head);

    insertAtBeginning(&head, 0);
    printList(&head);

    deleteNode(&head, 20);
    printList(&head);

    printf("\nProgrammed by Milan Bairagi...");

    return 0;
}